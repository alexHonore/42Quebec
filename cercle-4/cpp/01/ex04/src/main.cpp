#include <iostream>
#include <fstream>
#include <ctype.h>

int main (int argc, char** argv)
{
    if (argc != 4){
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::fstream ifs(argv[1]);
    std::string toReplace = argv[2];
    std::string replaceText = argv[3];
    if (ifs.fail()){
        std::cout << "Error opening the file" << std::endl;
        return 1;
    }
    std::string newFile = argv[1];
    newFile.append(".replace");
    std::ofstream ofs(newFile);
    std::string line;
    int i = 0;
    while(getline(ifs, line))
    {
         while (line.find(toReplace) != std::string::npos)
         {
            i = line.find(toReplace);
            line.erase(i, toReplace.length());
            line.insert(i, replaceText);
            i++;
         }
        ofs << line << std::endl;
        line.clear();
    }
    ofs.close();
    ifs.close();
    return 0;
}