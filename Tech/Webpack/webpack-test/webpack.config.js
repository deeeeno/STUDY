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
    module:{
        rules:[
            {
                test: /\.m?js$/i,
                exclude: /node_modules/,
                use: {
                    loader:'babel-loader',
                    options: {
                      presets: ['@babel/preset-env']
                    }
                  }
            },
        ]
    },
    mode: 'production',
    optimization: {minimizer:[]}
}