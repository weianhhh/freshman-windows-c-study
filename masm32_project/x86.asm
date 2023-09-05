.386
.model flat,stdcall
option casemap:none

include C:\masm32\include\windows.inc
include C:\masm32\include\user32.inc
includelib C:\masm32\lib\user32.lib
include C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib

.data

szCaption	db	'我的第一个汇编程序',0
szText      db	'Hello World!',0

.code

start:
	invoke MessageBox,NULL,offset szText,offset szCaption,MB_OK
	invoke ExitProcess,0
end start
