# smart_cmd for MSYS

If you're using MSYS, you can use smart_msys.exe which prints the current
path of the Windows Explorer.

Then create a .profile file in your MSYS home folder along with smart_msys.exe
and add:

```
cd $(./smart_msys.exe)
```

To pin the msys.bat file to your taskbar see:

http://superuser.com/questions/100249/how-to-pin-either-a-shortcut-or-a-batch-file-to-the-new-windows-7-taskbar
