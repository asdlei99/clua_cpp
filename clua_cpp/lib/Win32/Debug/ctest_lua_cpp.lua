local testlib = package.loadlib("cluacpp.dll","luaopen_MyLuaDLL");   --��ȡDLL���׳�������ַ 
print (testlib)  
if(testlib)then 
    testlib();  --����DLL���׳����� 
else 
    -- Error 
end 
                                                                        
MyLuaDLL.HelloWorld(); 
                                                                        
a,b=MyLuaDLL.average(23,33,3344); 
print("average:",a,"sum:",b);