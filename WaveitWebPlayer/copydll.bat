@echo off



echo Copying dlls...


xcopy "..\Bin\%1\*.dll" "..\WaveitLauncher\bin\" /Q /R /Y



EXIT
