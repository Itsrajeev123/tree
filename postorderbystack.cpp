class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> ans;
        int temp=0;
        while(node!=NULL || !st.empty()){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.pop();
                    st.pop();
                    ans(temp);
                    while(!st.empty()|| temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans(temp->val);
                    }
                }
                else{
                    node=temp;
                }
        }
        return ans;
    }
};
