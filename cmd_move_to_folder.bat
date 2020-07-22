@echo off
set /P oj="Input OJ name?(UVA[u],LightOJ[l],CodeChef[cc],Default-d)   :   "
set /P pname="Input Problem number-name?   :   "
IF %oj%==u  copy "E:\CP\New\main.cpp" "E:\CP\UVA\UVA_%pname%.cpp"
IF %oj%==l  copy "E:\CP\New\main.cpp" "E:\CP\lightoj\lightoj_%pname%.cpp"
IF %oj%==cc copy "E:\CP\New\main.cpp" "E:\CP\Codechef\Codechef_%pname%.cpp"
IF %oj%==d  copy "E:\CP\New\main.cpp" "E:\CP\%pname%.cpp"
pause