import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_yna/models/article_model.dart';
import 'package:flutter_yna/helper/news.dart';
import 'package:flutter_html/flutter_html.dart';
import 'package:flutter_yna/views/article_view.dart';

class CategoryNews extends StatefulWidget {
  final String category;
  CategoryNews({this.category});
  @override
  _CategoryNewsState createState() => _CategoryNewsState();
}

class _CategoryNewsState extends State<CategoryNews> {
  List<ArticleModel> articles = new List<ArticleModel>();
  bool _loading = true;

  void initState() {
    super.initState();
    getNews();
  }

  getNews() async {
    News newsClass = News();
    await newsClass.getDefaultNews();
    //await newsClass.getCategoryNews(widget.category);
    articles = newsClass.news;
    setState(() {
      _loading = false;
    });
  }

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
        body: _loading
            ? Center(
                child: Container(
                  child: CircularProgressIndicator(),
                ),
              )
            : SingleChildScrollView(
                child: Container(
                    child: Column(children: <Widget>[
                Container(
                  padding: EdgeInsets.only(top: 16),
                  child: ListView.builder(
                      itemCount: articles.length,
                      shrinkWrap: true,
                      physics: ClampingScrollPhysics(),
                      itemBuilder: (context, index) {
                        return BlogTile(
                            imageUrl: articles[index].urlToImage,
                            title: articles[index].title,
                            desc: articles[index].subTextBody,
                            cid: articles[index].cid,
                            newsUrl: articles[index].newsUrl);
                      }),
                )
              ]))));
  }
}

class BlogTile extends StatelessWidget {
  final String imageUrl, title, desc, cid, newsUrl;
  BlogTile(
      {@required this.imageUrl,
      @required this.title,
      @required this.desc,
      @required this.cid,
      @required this.newsUrl});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        print(this.cid);
        print(this.newsUrl);
        Navigator.push(
            context,
            MaterialPageRoute(
                builder: (context) => ArticleView(newsUrl: this.newsUrl)));
      },
      child: Container(
        margin: EdgeInsets.only(bottom: 16),
        child: Column(children: <Widget>[
          ClipRRect(
              borderRadius: BorderRadius.circular(6),
              child: Image.network(imageUrl)),
          Html(
              data: title,
              defaultTextStyle: TextStyle(
                  fontSize: 18,
                  color: Colors.black87,
                  fontWeight: FontWeight.w600)),
          SizedBox(height: 8),
          Html(data: desc, defaultTextStyle: TextStyle(color: Colors.black54))
        ]),
      ),
    );
  }
}
