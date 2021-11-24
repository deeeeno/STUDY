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
                include: [
                    path.resolve(__dirname, "src")
                  ],
                exclude: [
                    path.resolve(__dirname, "node_modules")
                ],
                use: {
                    loader:'babel-loader',
                    options: {
                      presets: ['@babel/preset-env']
                    }
                  }
            },
            {
                test: /\.css$/,
                use:["style-loader","css-loader"]
            },
        ]
    },
    mode: 'production',
    optimization: {minimizer:[]}
}