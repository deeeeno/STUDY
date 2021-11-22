const path = require('path')

module.exports = {
    entry : './src/index.js',
    output : {
        filename: 'main.js',
        path : path.resolve(__dirname,'dist')
    },
    resolve: {
        roots: [__dirname],
    },
    mode: 'production',
    optimization: {minimizer:[]}
}