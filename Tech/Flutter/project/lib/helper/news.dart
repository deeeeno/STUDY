import 'package:flutter_yna/models/article_model.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';
import 'package:charset_converter/charset_converter.dart';

class News {
  final String imageHost = "http://vmg.yonhapnews.co.kr";
  final String newsHost = "https://m.yna.co.kr/view/";
  final String defaultImg = "https://r.yna.co.kr/global/home/v01/img/yonhapnews_logo_600x600_kr01.jpg";
  List<ArticleModel> news = [];
  Future<void> getCategoryNews(String category) async {
    news = [];
    String url =
        'http://30.1.1.178:7003/qp?coll=KR_ARTICLE&sort=date&result=list&result_style=json_text&page_no=1&page_size=10&channel=basic_kr&dist_div=' +
            category;
    var request = http.Client();
    var jsonData;
    try {
      var res = await request.get(url);
      String _decoded = await CharsetConverter.decode('euc-kr', res.bodyBytes);
      jsonData = jsonDecode(_decoded);
    } catch (e) {
      print(e);
    }

    if (jsonData['KR_ARTICLE'] != null) {
      jsonData['KR_ARTICLE']['result'].forEach((element) {
        if ((element['INNER_FILE_INFO'] != null &&
                element['INNER_FILE_INFO'] != '') &&
            (element['TEXT_BODY'] != null && element['TEXT_BODY'] != '')) {
          String splitTextbody = (element['TEXT_BODY'].indexOf('스)') != -1)
              ? element['TEXT_BODY'].substring(
                  element['TEXT_BODY'].indexOf('스)') + 2,
                  element['TEXT_BODY'].length - 1)
              : "";
          ArticleModel articleModel = ArticleModel(
              author: element['WRITER_NAME'],
              title: element['TITLE'],
              textBody: splitTextbody,
              urlToImage: imageHost + element['INNER_FILE_INFO'],
              cid: element['CONTENTS_ID'],
              distDateTime: element['DIST_DATE'] + element['DIST_TIME'],
              subTextBody: (splitTextbody.length <= 100)
                  ? splitTextbody
                  : splitTextbody.substring(0, 90) + "...",
              newsUrl: newsHost + element['CONTENTS_ID']);
          news.add(articleModel);
        }
      });
    }
  }
  
  Future<void> getDefaultNews() async{
    news = [];
    for(var i=0; i<10; i++){
      ArticleModel articleModel = ArticleModel(
          author: "TEST_AUTHOR",
          title: "연합뉴스 기사[${i}]",
          textBody: "연합뉴스 테스트 기사를 만듭시다",
          urlToImage: defaultImg,
          cid: "AKR20201111",
          distDateTime: "202011110000",
          subTextBody: "연합뉴스 테스트 기사를 만듭시다",
          newsUrl: "https://m.yna.co.kr/view/AKR20201111052200530");
      news.add(articleModel);
    }
  }

  Future<void> getNews() async {
    news = [];
    String url =
        'http://30.1.1.178:7003/qp?coll=KR_ARTICLE&sort=date&result=list&result_style=json_text&page_no=1&page_size=10&channel=basic_kr';
    var request = http.Client();
    var jsonData;
    try {
      var res = await request.get(url);
      String _decoded = await CharsetConverter.decode('euc-kr', res.bodyBytes);
      jsonData = jsonDecode(_decoded);
    } catch (e) {
      print(e);
    }

    if (jsonData['KR_ARTICLE'] != null) {
      jsonData['KR_ARTICLE']['result'].forEach((element) {
        if ((element['INNER_FILE_INFO'] != null &&
                element['INNER_FILE_INFO'] != '') &&
            (element['TEXT_BODY'] != null && element['TEXT_BODY'] != '')) {
          String splitTextbody = (element['TEXT_BODY'].indexOf('스)') != -1)
              ? element['TEXT_BODY'].substring(
                  element['TEXT_BODY'].indexOf('스)') + 2,
                  element['TEXT_BODY'].length - 1)
              : "";
          ArticleModel articleModel = ArticleModel(
              author: element['WRITER_NAME'],
              title: element['TITLE'],
              textBody: splitTextbody,
              urlToImage: imageHost + element['INNER_FILE_INFO'],
              cid: element['CONTENTS_ID'],
              distDateTime: element['DIST_DATE'] + element['DIST_TIME'],
              subTextBody: (splitTextbody.length <= 100)
                  ? splitTextbody
                  : splitTextbody.substring(0, 90) + "...",
              newsUrl: newsHost + element['CONTENTS_ID']);
          news.add(articleModel);
        }
      });
    }
  }
}
