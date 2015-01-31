@echo off
setlocal enabledelayedexpansion
for %%i In (*.*.*.hex) Do (
	::echo %%i
	set /p var= <%%i
	::echo !var!
	if NOT !var!== :020000040000FA (
		echo :020000040000FA>temp.hex
		type %%i >> temp.hex
		del %%i
		ren temp.hex %%i
	)
	
)
timeout /T 1

::	Title		: Compatibility assistant for PDFUSB bootloader utility
::	Description	: This file checks MPLABX generated hex file whether it has the line of code offset.
::					If it is not present, it appends to the first line.
::	Author 		: Mohamed Basheer
::	email	 	: basheer@etiq.in
::	Company		: Etiq Technologies (http://etiq.in)