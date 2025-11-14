class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string res = "";
        stringstream ss(path);
        string temp;
        while(getline(ss, temp, '/')){
            cout << temp << endl;
            if(temp == ".."){
                if(!st.empty()) st.pop_back();
            }
            else if(temp != "." && !temp.empty()){
                st.push_back(temp);
            }
        }

        for(auto s : st){
            res = res + "/" + s;
        }
        if(res.empty()){
            return "/";
        }
        else{
            return res;
        }
    }
};