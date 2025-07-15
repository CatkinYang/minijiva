/* minijava 主程序 需要的模块
1. parser 类加载器子系统 解析class文件，读取它的binary，转换成classfile
2. classfile 解析后的class文件转换成classfile文件
   -  魔数 ✅
   -  次版本、主版本 ✅
   -  常量池入口 ✅
   -  常量池 ✅
   -  访问标志 ✅
   -  类索引 ✅
   -  父类索引 ✅
   -  接口数量、接口索引集合 ✅
   -  字段表数量、字段表 ✅
   -  方法表数量、方法表 ✅
   -  属性表数量、属性表 ✅
3. engine    执行引擎，用于根据engine的字节码执行程序
   - 运行时栈帧
      - 每一个栈帧：
        - 局部变量表
        - 操作数栈
        - 指向方法已解析的常量池引用
4. 内存空间
   - 方法区
   - heap
   - stack
   - local method stack
*/
