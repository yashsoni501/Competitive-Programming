def solution(s):
    c = s.count('<')
    d = s.count('>')
    ans = 0
    for i in s:
        if i=='<':
            c-=1
        elif i=='>':
            ans += c
            d-=1
    return ans*2