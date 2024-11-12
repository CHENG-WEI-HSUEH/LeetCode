//Test Case: 35min

class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> st;

        
        int n = path.size();
        for(int i = 1; i<n; i++)
        {
            if(path[i] == '/') continue; // 跳過 "/"

            string tmp;
            //取得該段目錄名字
            while(i < n && path[i] != '/')    tmp += path[i++];

            //目錄名字 為 "."
            if(tmp == ".")
            {
                continue; // 當前目錄，忽略
            }
            else if(tmp == "..")
            {
               if(!st.empty()) st.pop(); // 返回上一層，如果棧不為空
            }
            else
            {
                st.push(tmp); // 正常的目錄名或文件名
            }
        }

        // 組合結果路徑
        path = "";
        while(!st.empty())
        {
            path = "/" + st.top() + path;
            st.pop();
        }

        // 如果結果為空，返回根目錄 "/"
        return path.empty() ? "/" : path;

    }
};
