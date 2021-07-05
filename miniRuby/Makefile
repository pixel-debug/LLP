
CXX = g++
CXXFLAGS = -g -ggdb -O2 -Wall

TARGET = rubi
OBJS = rubi.o \
			lexical/SymbolTable.o lexical/LexicalAnalysis.o \
			syntatic/SyntaticAnalysis.o\
			interpreter/expr/AccessExpr.o\
			interpreter/expr/ArrayExpr.o\
			interpreter/expr/BinaryExpr.o\
			interpreter/expr/ConstExpr.o\
			interpreter/expr/CompositeBoolExpr.o\
			interpreter/expr/ConvExpr.o\
			interpreter/expr/FunctionExpr.o\
			interpreter/expr/InputExpr.o\
			interpreter/expr/NotBoolExpr.o\
			interpreter/expr/SingleBoolExpr.o\
			interpreter/expr/Variable.o\
			interpreter/command/AssignCommand.o\
			interpreter/command/BlocksCommand.o\
			interpreter/command/ForCommand.o\
			interpreter/command/IfCommand.o\
			interpreter/command/OutputCommand.o\
			interpreter/command/UnlessCommand.o\
			interpreter/command/UntilCommand.o\
			interpreter/command/WhileCommand.o\
			interpreter/value/ArrayValue.o\
			interpreter/value/IntegerValue.o\
			interpreter/value/StringValue.o\
			interpreter/util/Utils.o\
			interpreter/util/Memory.o\

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

rubi.o:

lexical/SymbolTable.o: lexical/TokenType.h

lexical/LexicalAnalysis.o: lexical/Lexeme.h lexical/SymbolTable.h

syntatic/SyntaticAnalysis.o: syntatic/SyntaticAnalysis.h

interpreter/expr/AccessExpr.o: interpreter/expr/AccessExpr.h

interpreter/expr/ArrayExpr.o: interpreter/expr/ArrayExpr.h

interpreter/expr/BinaryExpr.o: interpreter/expr/BinaryExpr.h

interpreter/expr/ConstExpr.o: interpreter/expr/ConstExpr.h

interpreter/expr/CompositeBoolExpr.o: interpreter/expr/CompositeBoolExpr.h

interpreter/expr/ConvExpr.o: interpreter/expr/ConvExpr.h

interpreter/expr/FunctionExpr.o: interpreter/expr/FunctionExpr.h

interpreter/expr/InputExpr.o: interpreter/expr/InputExpr.h

interpreter/expr/NotBoolExpr.o: interpreter/expr/NotBoolExpr.h

interpreter/expr/SingleBoolExpr.o: interpreter/expr/SingleBoolExpr.h

interpreter/expr/Variable.o: interpreter/expr/Variable.h

interpreter/command/AssignCommand.o: interpreter/command/AssignCommand.h

interpreter/command/BlocksCommand.o: interpreter/command/BlocksCommand.h

interpreter/command/ForCommand.o: interpreter/command/ForCommand.h

interpreter/command/IfCommand.o: interpreter/command/IfCommand.h

interpreter/command/OutputCommand.o: interpreter/command/OutputCommand.h

interpreter/command/UnlessCommand.o: interpreter/command/UnlessCommand.h

interpreter/command/UntilCommand.o: interpreter/command/UntilCommand.h

interpreter/command/WhileCommand.o: interpreter/command/WhileCommand.h

interpreter/value/ArrayValue.o: interpreter/value/ArrayValue.h

interpreter/value/IntegerValue.o: interpreter/value/IntegerValue.h

interpreter/value/StringValue.o: interpreter/value/StringValue.h

interpreter/util/Utils.o: interpreter/util/Utils.h

interpreter/util/Memory.o: interpreter/util/Memory.h

$(TARGET): $(OBJS)
		   $(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<


