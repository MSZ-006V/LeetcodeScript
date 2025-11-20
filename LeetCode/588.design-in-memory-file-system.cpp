class FileSystem {
struct Node{
    bool isFile;
    string content;
    map<string, Node*> child; // 题目要求使用字典序，因此使用map数据类型
    Node(): isFile(false), content("") {}
};

// 拆分路径，如把"/a/b/c"拆分成["a", "b", "c"]
vector<string> split(string& path){
    vector<string> res;
    string cur;
    for(char c : path){
        if(c == '/'){
            if(!cur.empty()){
                res.push_back(cur);
                cur.clear();
            }
        }
        else{
            cur.push_back(c);
        }
    }
    if(!cur.empty()) res.push_back(cur);
    return res;
}

// 根据路径从 root 向下查找对应的节点，若 create==true 则不存在的中间目录会被自动创建
Node* traverse(string& path, bool create = false){
    vector<string> parts = split(path);
    Node* cur = root;
    for(auto &p : parts){
        if(!cur->child.count(p)){ // 如果目前p这个目录还没有创建
            if(!create) return nullptr;
            cur->child[p] = new Node();
        }
        cur = cur->child[p];
    }
    return cur;
}

Node* root;
public:
    FileSystem() {
        root = new Node;
    }
    
    vector<string> ls(string path) {
        Node* node = traverse(path);
        vector<string> res;
        if(node->isFile){ // 是一个文件
            // 如果 path 指向一个文件（node->isFile==true）
            // 返回一个只含该文件名的向量（例如 ["file.txt"]）
            vector<string> parts = split(path);
            res.push_back(parts.back());
        }
        else{
            // 如果 path 指向一个目录
            // 则返回目录下的所有直接子项名称（文件和子目录名），按字典序（因为用了 map）
            for(auto &kv : node->child){
                res.push_back(kv.first);
            }
        }

        return res;
    }
    
    void mkdir(string path) {
        traverse(path, true);
    }
    
    void addContentToFile(string filePath, string content) {
        Node* node = traverse(filePath, true);
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        return traverse(filePath)->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */