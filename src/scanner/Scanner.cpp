/*******************************************
*  @file  Scanner.cpp                      * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "Scanner.h"

/**
* @brief constructor 
*
* @param in input stream 
*
*/
Scanner::Scanner(istream& in)
    :m_line(1),
    m_position(1),
    m_curr(0),
    m_is_eof(false),
    m_str_cache(0),
    m_in(in) { 

}

/**
* @brief scan next character which is not space.
*
* @return Return which is eof.
*/
bool Scanner::next() {
    m_in.get(m_curr);
    // check eof flag
    if (m_in.eof()) {
        m_is_eof = true;
        m_curr = 0;
    } else { 
         if (m_curr == '\n')
            newLine();
        else
            m_position ++;
    }
    return !m_is_eof;
}

/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @return Return parameter description
 */
bool Scanner::skip() {
    while(next()) {
        if (!isspace(m_curr) && m_curr != '\n') return true;
    }
    return false;
}