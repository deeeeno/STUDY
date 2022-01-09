import 'package:flutter_yna/models/category_model.dart';
import 'dart:io';
import 'dart:convert';

final categoryJsonFilePath =
    "C:/Users/yna/Desktop/myapp/resources/category.json";

List<CategoryModel> getCategories() {
  List<CategoryModel> category = new List<CategoryModel>();
  CategoryModel categoryModel = new CategoryModel();

  categoryModel.categoryName = "정치";
  categoryModel.categoryCode = "01";
  categoryModel.imageUrl =
      "https://www1.president.go.kr/images/cheongwadae/pic_introduction_01_01.jpg";
  category.add(categoryModel);

  categoryModel = new CategoryModel();
  categoryModel.categoryName = "경제";
  categoryModel.categoryCode = "02";
  categoryModel.imageUrl =
      "https://images.unsplash.com/photo-1526304640581-d334cdbbf45e?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80";
  category.add(categoryModel);

  categoryModel = new CategoryModel();
  categoryModel.categoryName = "사회";
  categoryModel.categoryCode = "03";
  categoryModel.imageUrl =
      "https://images.unsplash.com/photo-1517154421773-0529f29ea451?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80";
  category.add(categoryModel);

  categoryModel = new CategoryModel();
  categoryModel.categoryName = "문화";
  categoryModel.categoryCode = "04";
  categoryModel.imageUrl =
      "https://images.unsplash.com/photo-1557018250-c58928b114a3?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1489&q=80";
  category.add(categoryModel);

  categoryModel = new CategoryModel();
  categoryModel.categoryName = "스포츠";
  categoryModel.categoryCode = "05";
  categoryModel.imageUrl =
      "https://images.unsplash.com/photo-1502904550040-7534597429ae?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1549&q=80";
  category.add(categoryModel);

  categoryModel = new CategoryModel();
  categoryModel.categoryName = "IT/과학";
  categoryModel.categoryCode = "08";
  categoryModel.imageUrl =
      "https://images.unsplash.com/photo-1532094349884-543bc11b234d?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1350&q=80";
  category.add(categoryModel);
  return category;
}
