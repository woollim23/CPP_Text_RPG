@echo off
chcp 65001 >nul
setlocal

REM =====================================================
REM  .gitignore 적용 + 캐시 초기화 + 재추가 자동화 스크립트
REM  더블클릭으로 실행하거나, 명령창에서 fix_gitignore.bat 입력
REM =====================================================

cd /d "%~dp0"

echo.
echo ===========================================
echo  [1/5] 현재 위치: %CD%
echo ===========================================
echo.

echo ===========================================
echo  [2/5] git 캐시 초기화 (실제 파일은 보존)
echo  실행 명령: git rm -r --cached .
echo ===========================================
git rm -r --cached . >nul 2>&1
echo  완료.
echo.

echo ===========================================
echo  [3/5] .gitignore 기준으로 다시 추가
echo  실행 명령: git add .
echo ===========================================
git add .
echo.

echo ===========================================
echo  [4/5] 스테이징된 파일 목록 (.cpp / .h / .sln / .vcxproj 만 보여야 정상)
echo ===========================================
git status --short
echo.

echo ===========================================
echo  [5/5] 혹시 .ipch / .vs / x64 / .user / .obj 가 잡히는지 검사
echo ===========================================
git diff --cached --name-only | findstr /R /C:"\.ipch" /C:"^\.vs/" /C:"/x64/" /C:"\.user$" /C:"\.obj$" /C:"\.pdb$"
if errorlevel 1 (
    echo  통과: 깃에 올라가면 안 되는 파일이 하나도 없습니다.
) else (
    echo  경고: 위 파일들이 아직 잡혔습니다. 채소에게 알려주세요.
)
echo.

echo ===========================================
echo  완료!
echo  이제 Visual Studio의 Git Changes 창으로 돌아가서
echo  커밋 메시지 적고 Commit + Push 하시면 됩니다.
echo  (또는 이 창에서 직접 git commit -m "메시지" 실행)
echo ===========================================
echo.

pause
endlocal
