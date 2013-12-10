# smart_cmd for MSYS

If you're using MSYS, you can use
[smart_msys.exe](https://github.com/jhasse/smart_cmd/releases/download/v1.0/smart_msys.exe)
which prints the current path of the Windows Explorer.

Then create a .profile file in your MSYS home folder along with smart_msys.exe
and add:

```
cd $(./smart_msys.exe)
```

To pin the MSYS to the taskbar use [mintty](http://code.google.com/p/mintty/).
