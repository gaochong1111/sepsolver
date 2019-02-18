#if !defined(Z3BUFFER_)
#define Z3BUFFER_
/*******************************************
*  @file  Z3Buffer.h                       *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-17                     *
*                                          *
*******************************************/

#include "z3++.h"
#include "Var.h"
#include "SortType.h"
#include "FuncType.h"
#include <map>
#include "Parser.h"

using namespace z3;
using std::map;

class Z3Buffer {
public:
    Z3Buffer() {}

    sort& getSort(SortType* pst); 

    expr& getVar(Var* pvar);

    func_decl getFuncDecl(FuncType* pft, ArgTypeList& arg_type_list, Parser& parser);

protected:
    map<string, sort> z3_sort_table;
    map<string, expr> z3_var_table;
    map<string, func_decl> z3_fun_table; 
};


#endif