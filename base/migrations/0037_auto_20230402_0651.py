# Generated by Django 3.0.5 on 2023-04-02 01:21

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('base', '0036_auto_20230402_0650'),
    ]

    operations = [
        migrations.AlterField(
            model_name='student',
            name='role_no',
            field=models.IntegerField(),
        ),
    ]