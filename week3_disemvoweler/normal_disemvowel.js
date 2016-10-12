var disemvowel = function(str) {
    var f = '';
    var a = '';
    for (var i = 0; i < str.length; i++) {
        if ('aeiou'.indexOf(str.split('')[i]) == -1) {
            f = f + str.split('')[i];
        } else {
            a = a + str.split('')[i];
        }
    };
    return f + '\n' + a;
};

console.log(disemvowel('Hello World'));
