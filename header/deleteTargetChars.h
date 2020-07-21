//
// Created by yz L on 2019-09-10.
//
/***
 * 在字符串中删除特定的字符
 * 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
 * 例如，输入”They are students.” 和”aeiou” ，则删除之后的第一个字符串变成”Thy r stdnts.”
 */

#ifndef ALG_DELETETARGETCHARS_H
#define ALG_DELETETARGETCHARS_H
class CDeleteTarget {
public:
    /**
     * delete target chars from src
     * @param src
     * @param delTarget
     * @return if success 0, else -1.
     */
    int delTargetChars(char* src, const char* delTarget);

    /**
     * code optimize.
     * @param src
     * @param delTarget
     * @return
     */
    int delTargetCharsBetter(char* src, const char* delTarget);
};
#endif //ALG_DELETETARGETCHARS_H
