# Generated by Django 4.1.9 on 2023-07-21 06:54

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('base', '0082_alter_blog_blog_profile_img_alter_details_image_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='teacher',
            name='profile_pic',
            field=models.ImageField(blank=True, default='images/teacher.webp', null=True, upload_to='Teacher_images/'),
        ),
    ]
