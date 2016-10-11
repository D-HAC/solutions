# Just does basic disemvoweling.
disemvowel = lambda s: ''.join([(lambda v: '' if v in 'aeiou' else v)(v) for v in list(s)])

# Proper disemvoweling!
disemvowelWithVowels = lambda s: [''.join([(lambda v: '' if v in 'aeiou' else v)(v) for v in list(s)]), ''.join([(lambda v: v if v in 'aeiou' else '')(v) for v in list(s)])]

# print(disemvowel('Yet another one line solution.'))

[print(s) for s in disemvowelWithVowels('Yet another one line solution. Who said python had to be easy!')]
