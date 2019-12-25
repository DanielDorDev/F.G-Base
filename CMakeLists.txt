cmake_minimum_required(VERSION 3.13)
project(FlightGear)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(FlightGear main.cpp Utility/ExecuteInterpreter.cpp Utility/ExecuteInterpreter.h Utility/Interface/Interpreter.h Utility/Interface/ILexer.h Utility/Interface/IParser.h Utility/FlightLexer.cpp Utility/FlightLexer.h Utility/FlightParser.cpp Utility/FlightParser.h Utility/Interface/ISymbolTable.h Utility/FlightSymbolTable.cpp Utility/FlightSymbolTable.h Utility/Interface/ICommand.h Utility/CommandPool.cpp Utility/CommandPool.h Utility/NotImplementedException.h Utility/Interface/IFactory.h Utility/FlightCommandFactory.cpp Utility/FlightCommandFactory.h)