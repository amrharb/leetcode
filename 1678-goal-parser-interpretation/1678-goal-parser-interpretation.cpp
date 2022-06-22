class Solution {
public:
    string interpret(string command) {
        int k=command.find("()");
        while(k!=-1){
            command.replace(k,2,"o");
            k=command.find("()");
        }
        k=command.find("(al)");
        while(k!=-1){
            command.replace(k,4,"al");
            k=command.find("(al)");
        }
        return command;
    }
};