;ucrt.lib;vcruntime.lib;legacy_stdio_definitions.lib
extern printf:proc
extern ExitProcess:proc

.data
    msg db 'Hello Worldwww���!', 0

.code
mainCRTStartup proc
    sub     rsp, 28h

    lea     rcx, [msg]
    call    printf

    xor     rcx, rcx
    call    ExitProcess
mainCRTStartup endp
end
