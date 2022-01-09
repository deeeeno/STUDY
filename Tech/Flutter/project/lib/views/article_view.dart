import 'package:flutter/material.dart';
import 'package:webview_flutter/webview_flutter.dart';
import 'dart:async';

class ArticleView extends StatefulWidget {
  final String newsUrl;
  ArticleView({this.newsUrl});
  @override
  _ArticleViewState createState() => _ArticleViewState();
}

class _ArticleViewState extends State<ArticleView> {
  final Completer<WebViewController> _controller =
      Completer<WebViewController>();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Row(
            children: <Widget>[],
          ),
          centerTitle: true,
          elevation: 0.0,
        ),
        body: Container(
            child: WebView(
                initialUrl: widget.newsUrl,
                onWebViewCreated: ((WebViewController webViewController) {
                  _controller.complete(webViewController);
                }))));
  }
}
