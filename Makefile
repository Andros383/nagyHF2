all:
	g++ -fdiagnostics-color=always -g basic_components/*.cpp *.cpp -DMEMTRACE -o main.exe && main