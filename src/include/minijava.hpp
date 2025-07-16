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
      - Code属性表 ✅
      - 其余属性暂时都以raw属性填充
3. engine    执行引擎
   - 指令集
      - 根据method_info中的code属性取指令执行
   - 运行时栈帧 Stack ✅
      - 每一个栈帧： StackFrame
        - 局部变量表 LocalVarTable ✅
        - 操作数栈   OptNumStack ✅
        - 指向方法已解析的常量池引用

4. 内存空间
   - 方法区
   - heap
   - stack
   - local method stack
*/

/* todo
1. sum只生成了一个类，加载一个类文件,
    spilt 涉及两个类，类调用另一个类中的函数,
    需要加载两个类文件?
2. instruction 设计
   执行的时候，引擎首先需要为当前方法创建一个栈帧
   栈帧初始化需要根据当前方法的Code属性进行初始化
   初始化 LocalVarTable、OptNumStack....
   写指令
*/
