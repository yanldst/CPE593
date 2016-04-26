/*
 * Using ExpressionTree to Calculate RPN
 * Lei Yan
 *
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

class TreeNode
{
    public:
        char data;
        TreeNode *left, *right;
        TreeNode(char data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class StackNode
{
    public:
        TreeNode *treeNode;
        StackNode *next;
        StackNode(TreeNode *tn)
        {
            this->treeNode = tn;
            next = NULL;
        }
};


class ExpressionTree
{
    private:
        StackNode *top;
    public:
        ExpressionTree()
        {
            top = NULL;
        }

        void push(TreeNode *treeptr)
        {
            if (top == NULL)
                top = new StackNode(treeptr);
            else
            {
                StackNode *nptr = new StackNode(treeptr);
                nptr->next = top;
                top = nptr;
            }
        }

        TreeNode *pop()
        {
            if (top == NULL)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                TreeNode *treeptr = top->treeNode;
                top = top->next;
                return treeptr;
            }
            return 0;
        }

        TreeNode *peek()
        {
            return top->treeNode;
        }

        void insert(char val)
        {
            if (isOperand(val))
            {
                TreeNode *nptr = new TreeNode(val);
                push(nptr);
            }
            else if (isOperator(val))
            {
                TreeNode *nptr = new TreeNode(val);
                nptr->right = pop();
                nptr->left = pop();
                push(nptr);
            }
            else
            {
                cout<<"Invalid Expression"<<endl;
                return;
            }
        }

        bool isOperand(char ch)
        {
            return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ;
        }

        bool isOperator(char ch)
        {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
        }

        //simply convert english letters to their order in alphabet
        //I can only deal with single digit numbers
        int toDigit(char ch)
        {
            if(ch >= '0' && ch <= '9')
                return ch - '0';
            if(ch >= 'a' && ch <= 'z')
                return ch - 'a';
            if(ch >= 'A' && ch <= 'Z')
                return ch - 'A';
            return 0;
        }

        void buildTree(string equation)
        {
            int len = equation.length();
            for (int i = 0; i <= len - 1; i++)
                insert(equation[i]);
        }

        double evaluate()
        {
            return evaluate(peek());
        }

        double evaluate(TreeNode *ptr)
        {
            if (ptr->left == NULL && ptr->right == NULL)
                return toDigit(ptr->data);
            else
            {
                int result = 0;
                int left = evaluate(ptr->left);
                int right = evaluate(ptr->right);
                char op = ptr->data;
                switch (op)
                {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    if(right == 0)
                        result = INT_MAX;
                    else
                        result = left / right;
                    break;
                case '%':
                    result = left % right;
                    break;
                case '^':
                    result = pow(left , right);
                    break;
                }
                return result;
            }
        }

        void infix()
        {
            inOrder(peek());
        }

        void inOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                inOrder(ptr->left);
                cout<<ptr->data;
                inOrder(ptr->right);
            }
        }

        void prefix()
        {
            preOrder(peek());
        }

        void preOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                cout<<ptr->data;
                preOrder(ptr->left);
                preOrder(ptr->right);
            }
        }
};


int main()
{
    string s;
    cout<<"--------------Expression Tree Test---------------"<<endl;
    ExpressionTree etree;
    cout<<"\nEnter equation in Postfix form (without spaces):\n";
    cin>>s;
    etree.buildTree(s);
    cout<<"\nPrefix  : ";
    etree.prefix();
    cout<<"\n\nInfix   : ";
    etree.infix();
    cout<<"\n\nEvaluated Result : "<<etree.evaluate();
    return 0;
}
