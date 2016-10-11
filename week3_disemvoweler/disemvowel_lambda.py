disemvowel = lambda s: ''.join([(lambda v: '' if v in 'aeiou' else v)(v) for v in list(s)])

# print(disemvowel('Yet another one line solution.'))
