#include<iostream>
#include<cstdio>
using namespace std;
class node{
        public:
        float key;
        node *left,*right;
};
class tree{
        public:
        node *root,*current;
        tree(){
                root=new node();
                root->left=NULL;
                root->right=NULL;
                root->key=1.0;
                current=root;
        }
        void insert(float a,float b,bool flag){
                node *x=new node();
                node *y=new node();
                x->key=a;y->key=b;
                x->left=NULL;x->right=NULL;
                y->left=NULL;y->right=NULL;
                current->left=x;
                current->right=y;
                if(flag){
                if(a==b)
                	current=x;
                	else current=y;
                }
                else current=x;
              
        }
        string search(float match){
                string ans="";
                node *x=root;
                while(1){
                        if(x->left->left==NULL && x->right->left==NULL){
                        	if(x->left->key==match)
                        		ans+='1';
                       		else
                        		ans+='0';
                        	return ans;	
                        }
                        if(x->left->left==NULL){
                                if(x->left->key==match){ 
                                        ans+='1';
                                        return ans;
                                }
                                ans+='0';
                                x=x->right;
                        }
                        else if(x->right->left==NULL){
                                if(x->right->key==match){
                                        ans+='0'; 
                                        return ans;
                                }
                                ans+='1';
                                x=x->left;
                        }
        	 }

       }
};
tree jj;
void solve(float p[],int n,int c){
        if(c==(n-1))return;
        float a=p[c],b=0;
        for(int i=c+1;i<n;i++)b+=p[i];
        if(a<=b)jj.insert(a,b,true);
        else jj.insert(b,a,false);
        solve(p,n,c+1);
}
int main(){
        int n;float t;
        printf("How many symbols?\n");
        scanf("%d",&n);
        float *p=new float[n];
        string *ans=new string[n];
        printf("Enter the probablities:\n");
        for(int i=0;i<n;i++)
                scanf("%f",&p[i]);
	for(int i=0;i<sizeof(p);i++)
                for(int j=i+1;j<sizeof(p);j++)
                        if(p[i]<p[j]){
                                t=p[i];
                                p[i]=p[j];
                                p[j]=t;
                        }
        solve(p,n,0);
        for(int i=0;i<n;i++)
        ans[i]=jj.search(p[i]);
        for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                        if(ans[i]==ans[j]){
                                ans[i][ans[i].length()-1]='1';
                                ans[j][ans[j].length()-1]='0';
                                break;
                        }
        printf("\t\t\t***Huffmann Code***\n");
        for(int i=0;i<n;i++)printf("%s\n",ans[i].c_str());
}
