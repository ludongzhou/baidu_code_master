#include "parser_driver.h"
#include "word_table.h"
#include "factory.h"

using std::cout;
using std::endl;
using std::cerr;

int main(){
    std::string file_path = "test.txt";
    wp::WordTable table;
    wp::ParserDriver pd;
    if(pd.set_type(file_path, 1, "string") != 0){
        cerr << "Error: set type failed, " << endl;
    }
    table.set_types(pd.get_types(file_path));
    table.set_content(pd.get_content(file_path));
    std::vector<wp::CommonParser*> row;
    while(true){
        int dummy = table.get_row(row);
        if (dummy != 0){
            continue;
        }
        else if(dummy == 0 && row.size() == 0){
            cout << "----------------\n" << "End of File" << endl;
            break;
        }
        cout << "----------------\n";
        for(int i = 0; i < row.size(); i++){
            cout << table.get_type(i) << ": " << row[i]->to_string() << endl;
        }
        for(int i = 0; i < row.size(); i++){
	        delete row[i];
        }
        row.clear();
    }
    return 0;
}

