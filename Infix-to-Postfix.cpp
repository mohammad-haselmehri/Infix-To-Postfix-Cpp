//
// Created by mohammad on 5/7/21.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack <string> Equation_Operator;
    string Equation_Item,Operator_Item_one;
    string Equation_Str,Finally_Equation="";
    cout<<"Please Enter Your Equation:\t";
    cin>>Equation_Str;
    for (int i=0;i<Equation_Str.length();i++){
        Equation_Item = Equation_Str[i];
        if ((Equation_Item.compare("+")==0
             || Equation_Item.compare("-")==0
             || Equation_Item.compare("/")==0
             || Equation_Item.compare("*")==0
             || Equation_Item.compare("^")==0)
            && Equation_Operator.size() !=0){
            Operator_Item_one = Equation_Operator.top();
            //Calc + Or -
            if((Equation_Item == "+"
                || Equation_Item == "-")
               && (Operator_Item_one != "/"
                   && Operator_Item_one != "*"
                   && Operator_Item_one != "^"
                   && Operator_Item_one!= "+"
                   && Operator_Item_one!= "-")){
                Equation_Operator.push(Equation_Item);
            } else if((Equation_Item == "+"
                       || Equation_Item == "-")
                      && (Operator_Item_one == "/"
                          || Operator_Item_one == "*"
                          || Operator_Item_one == "^"
                          || Operator_Item_one== "+"
                          || Operator_Item_one== "-")){
                Operator_Item_one = Equation_Operator.top();
                if ((Equation_Item == "+"
                     || Equation_Item == "-")
                    && (Operator_Item_one == "+"
                        || Operator_Item_one == "-")){
                    while (Operator_Item_one != "("
                           && Equation_Operator.size() != 0){
                        Finally_Equation+=Operator_Item_one;
                        Equation_Operator.pop();
                        if (Equation_Operator.size() != 0){
                            Operator_Item_one = Equation_Operator.top();
                        }
                    }
                    Equation_Operator.push(Equation_Item);
                }else if((Equation_Item == "+"
                          || Equation_Item == "-")
                         && (Operator_Item_one != "+"
                             && Operator_Item_one != "-")){
                    Equation_Operator.push(Equation_Item);
                }
                //Calc / Or *
            }else if((Equation_Item == "/"
                      || Equation_Item == "*")
                     && (Operator_Item_one != "/"
                         && Operator_Item_one != "*"
                         && Operator_Item_one != "^")){
                Equation_Operator.push(Equation_Item);
            } else if((Equation_Item == "/"
                       || Equation_Item == "*")
                      && (Operator_Item_one == "/"
                          || Operator_Item_one == "*"
                          || Operator_Item_one == "^")){
                Operator_Item_one = Equation_Operator.top();
                if ((Equation_Item == "/"
                     || Equation_Item == "*")
                    && (Operator_Item_one == "/"
                        || Operator_Item_one == "*"
                        || Operator_Item_one == "^")){
                    while (Operator_Item_one != "("
                           && Equation_Operator.size() != 0
                           && Operator_Item_one != "/"
                           && Operator_Item_one != "*"
                           && Operator_Item_one != "^"
                            ){
                        Finally_Equation+=Operator_Item_one;
                        Equation_Operator.pop();
                        if (Equation_Operator.size() != 0){
                            Operator_Item_one = Equation_Operator.top();
                        }
                    }
                    Equation_Operator.push(Equation_Item);
                }else if((Equation_Item == "/"|| Equation_Item == "*")
                         && (Operator_Item_one != "/"
                             && Operator_Item_one == "*"
                             && Operator_Item_one != "^")){
                    Equation_Operator.push(Equation_Item);
                }
                //Start Calc ^
            }else if(Equation_Item == "^"
                     && Operator_Item_one != "^"){
                Equation_Operator.push(Equation_Item);
            } else if(Equation_Item == "^"
                      && Operator_Item_one == "^"){
                Operator_Item_one = Equation_Operator.top();
                if ((Equation_Item == "^")
                    && (Operator_Item_one == "^")){
                    while (Operator_Item_one != "("
                           && Operator_Item_one != "^"
                           && Equation_Operator.size() != 0){
                        Finally_Equation+=Operator_Item_one;
                        Equation_Operator.pop();
                        if (Equation_Operator.size() != 0){
                            Operator_Item_one = Equation_Operator.top();
                        }
                    }
                    Equation_Operator.push(Equation_Item);
                }else if((Equation_Item == "^")
                         && (Operator_Item_one != "^")){
                    Equation_Operator.push(Equation_Item);
                }
            }
            //End Calc ^
        }else if ((Equation_Item.compare("+")==0
                   || Equation_Item.compare("-")==0
                   || Equation_Item.compare("/")==0
                   || Equation_Item.compare("*")==0
                   || Equation_Item.compare("^")==0)
                  && Equation_Operator.size() == 0){
            Equation_Operator.push(Equation_Item);
        }else if(Equation_Item.compare("+")!=0
                 && Equation_Item.compare("-")!=0
                 && Equation_Item.compare("/")!=0
                 && Equation_Item.compare("*")!=0
                 && Equation_Item.compare("^")!=0
                 && Equation_Item.compare("(")!=0
                 && Equation_Item.compare(")")!=0
                ){
            Finally_Equation+=Equation_Item;
        }else if(Equation_Item.compare("(")==0
                 || Equation_Item.compare(")")==0){

            if (Equation_Item.compare("(")==0){
                Equation_Operator.push(Equation_Item);
            }else if(Equation_Item.compare(")")==0
                     && Equation_Operator.size() !=0){
                Operator_Item_one = Equation_Operator.top();
                while (Operator_Item_one != "("
                       && Equation_Operator.size() !=0){
                    Finally_Equation+=Operator_Item_one;
                    Equation_Operator.pop();
                    if (Equation_Operator.size() !=0){
                        Operator_Item_one = Equation_Operator.top();
                    }
                }
                if(Operator_Item_one == "("
                   && Equation_Operator.size() !=0){
                    Equation_Operator.pop();
                }
            }
        }
    }
    if(!Equation_Operator.empty()){
        Operator_Item_one = Equation_Operator.top();
        while (!Equation_Operator.empty()){
            if (Operator_Item_one != "("){
                Finally_Equation+=Equation_Operator.top();
                Equation_Operator.pop();
            }else{
                Equation_Operator.pop();
            }
        }
    }
    cout<<"Postfix:\t"<<Finally_Equation<<endl;
}