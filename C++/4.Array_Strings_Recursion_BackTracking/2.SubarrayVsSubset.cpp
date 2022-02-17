#include <bits/stdc++.h>
using namespace std;


int main(){

    //Subarray: Contigious sequence of elements within an array
    //Eg1: {1,2,1} = {1}, {2}, {1,2}, {2,1}, {1,2,1}, {}
    //Eg2: {1,2,3} = {1}, {2}, {3}, {1,2}, {2,3}, {1,2,3}, {}


    //Substring: Same as subarray but in context of a string
    //Eg: "ara" = "a", "r", "ar", "ra", "ara", ""


    //Subsequence: A sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements
    //(Not contigious but order is preserver i.e. <a,a,b> & <b,a,a> are not preserving the order)
    //Eg: <a,b,a> = <a>, <b>, <a,b> , <b,a>, <a,a>, <a,b,a>, <>


    //Subset: A set is subset of another set if all its elements are contained by that set.
    //(Do not need to be contigous & donot even preserve element order)
    //(Unlike subarray, substring, subsequence sets do not allow duplicates)
    //Eg: {1,2,3} = {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}, {}
}