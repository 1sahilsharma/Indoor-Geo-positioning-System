# -*- coding: utf-8 -*-
# Generated by Django 1.10.2 on 2016-11-17 05:47
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('lab', '0007_delete_prof'),
    ]

    operations = [
        migrations.CreateModel(
            name='dump',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=30)),
                ('room', models.CharField(default='', max_length=30)),
                ('time', models.CharField(blank=True, default='', max_length=50)),
            ],
        ),
    ]
