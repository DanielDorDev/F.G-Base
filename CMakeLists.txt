cmake_minimum_required(VERSION 3.13)
project(FlightGear)
set(CMAKE_CXX_STANDARD 14 )
SET(CMAKE_CXX_FLAGS -std=c++11)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(
        FlightGear main.cpp
        Utility/ExecuteInterpreter.cpp
        Utility/ExecuteInterpreter.h Utility/Interface/Interpreter.h
        Utility/Interface/ILexer.h Utility/Interface/IParser.h
        Utility/FlightLexer.cpp
        Utility/FlightLexer.h Utility/FlightParser.cpp Utility/FlightParser.h
        Utility/Interface/ICommand.h Utility/Model/CommandPool.cpp
        Utility/Model/CommandPool.h Utility/Exception/NotImplementedException.h
        Utility/Interface/IFactory.h Utility/Model/FlightCommandFactory.cpp
        Utility/Model/FlightCommandFactory.h
        Utility/Exception/InvalidCommand.h Utility/Exception/NoCommandExist.h
        Utility/Model/SampleTable.cpp Utility/Model/SampleTable.h

        Utility/Model/DataReaderServer.cpp
        Utility/Model/DataReaderServer.h Commands/ConnectCommand.cpp
        Commands/ConnectCommand.h Commands/VarCommand.cpp
        Commands/VarCommand.h Utility/Model/ClientWriter.cpp
        Utility/Model/ClientWriter.h Commands/SleepCommand.h
        Commands/PrintCommand.h Commands/BindCommand.cpp
        Commands/BindCommand.h Commands/IfCommand.cpp
        Commands/IfCommand.h Commands/WhileCommand.cpp
        Commands/WhileCommand.h
        Commands/OpenServerCommand.cpp Commands/OpenServerCommand.h
        Expression/BinaryExpression.cpp Expression/BinaryExpression.h
        Expression/Different.cpp Expression/Different.h Expression/Div.h
        Expression/Div.cpp Expression/Equal.h Expression/Equal.cpp
        Expression/Expression.h Expression/Greater.h Expression/Greater.cpp
        Expression/GreaterEqual.h Expression/GreaterEqual.cpp Expression/Minus.cpp
        Expression/Minus.h Expression/Mult.cpp Expression/Mult.h
        Expression/Negative.h Expression/Negative.cpp Expression/Number.h
        Expression/Number.cpp Expression/Plus.h Expression/Plus.cpp
        Expression/Smaller.h Expression/Smaller.cpp
        Expression/SmallerEqual.h Expression/SmallerEqual.cpp
        Expression/UnaryExpression.cpp Expression/UnaryExpression.h
        Utility/Model/ShuntingYard.h Utility/Model/ShuntingYard.cpp


        Expression/VarExpression.cpp Expression/VarExpression.h Commands/AssignCommand.h Utility/Interface/IPrintExpression.h Expression/ExpPrintExpression.h Expression/StringPrintExpression.h Expression/PrintListExpression.h)