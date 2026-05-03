@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

REM =====================================================
REM  Visual Studio C++ 프로젝트 캐시 / 빌드 결과물 청소
REM  (소스코드 / 솔루션 / 프로젝트 파일은 절대 건드리지 않음)
REM
REM  지워지는 것:
REM    - .vs\               (VS IntelliSense 캐시, 사용자 설정)
REM    - **\x64\            (빌드 결과 폴더)
REM    - **\Debug\          (빌드 결과 폴더)
REM    - **\Release\         (빌드 결과 폴더)
REM    - *.vcxproj.user     (디버깅 환경 등 개인 설정)
REM    - *.suo *.sdf *.opensdf *.VC.db *.VC.opendb
REM    - *.ipch *.pch *.pdb *.idb *.ilk *.iobj *.ipdb
REM    - *.tlog *.log *.recipe *.obj
REM
REM  ⚠ 실행 전에 Visual Studio를 닫아주세요.
REM =====================================================

cd /d "%~dp0"

echo.
echo ===========================================
echo  실행 위치: %CD%
echo ===========================================
echo.
echo  Visual Studio가 열려 있으면 잠긴 파일이 안 지워질 수 있어요.
echo  열려 있다면 닫고 아무 키나 누르세요. (또는 Ctrl+C로 취소)
echo.
pause
echo.

set DELETED=0
set FAILED=0

echo ===========================================
echo  [1/4] .vs 폴더 삭제
echo ===========================================
if exist ".vs" (
    rmdir /s /q ".vs" 2>nul
    if exist ".vs" (
        echo   실패: .vs 폴더가 안 지워졌어요. VS를 닫고 다시 시도해주세요.
        set /a FAILED+=1
    ) else (
        echo   삭제 완료: .vs
        set /a DELETED+=1
    )
) else (
    echo   .vs 폴더 없음. 건너뜀.
)
echo.

echo ===========================================
echo  [2/4] 빌드 출력 폴더 (x64, Debug, Release) 삭제
echo ===========================================
for /d /r %%D in (x64 Debug Release) do (
    if exist "%%D" (
        rmdir /s /q "%%D" 2>nul
        if exist "%%D" (
            echo   실패: %%D
            set /a FAILED+=1
        ) else (
            echo   삭제: %%D
            set /a DELETED+=1
        )
    )
)
echo.

echo ===========================================
echo  [3/4] 사용자 개인 설정 / 캐시 파일 삭제
echo ===========================================
for %%E in (*.vcxproj.user *.suo *.sdf *.opensdf *.VC.db *.VC.opendb) do (
    for /r %%F in ("%%E") do (
        if exist "%%F" (
            del /f /q "%%F" >nul 2>&1
            echo   삭제: %%F
            set /a DELETED+=1
        )
    )
)
echo.

echo ===========================================
echo  [4/4] 빌드 산출물 / 로그 파일 삭제
echo ===========================================
for %%E in (*.ipch *.pch *.pdb *.idb *.ilk *.iobj *.ipdb *.tlog *.log *.recipe *.obj) do (
    for /r %%F in ("%%E") do (
        if exist "%%F" (
            del /f /q "%%F" >nul 2>&1
            echo   삭제: %%F
            set /a DELETED+=1
        )
    )
)
echo.

echo ===========================================
echo  결과 요약
echo  성공: !DELETED!개
echo  실패: !FAILED!개
echo ===========================================
echo.

if !FAILED! gtr 0 (
    echo  실패한 항목이 있다면 Visual Studio가 열려 있을 가능성이 큽니다.
    echo  VS 닫고 이 스크립트를 한 번 더 실행해주세요.
) else (
    echo  깨끗하게 정리됐습니다!
    echo  솔루션 다시 열고 빌드하면 필요한 캐시는 VS가 자동으로 다시 만들어줍니다.
)
echo.

pause
endlocal
