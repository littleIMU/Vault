Table ID## Reference

[obsidian dataview for beginners](https://denisetodd.medium.com/obsidian-dataview-for-beginners-a-checklist-to-help-fix-your-dataview-queries-11acc57f1e48)

**Default element lile: 
```
path: example/backlink/Untitled.md, 
folder: example/backlink, 
name: Untitled, 
link: Untitled, 
outlinks: <empty list>, 
inlinks: <empty list>, 
etags: <empty list>, 
tags: <empty list>, 
aliases: <empty list>, 
lists: <empty list>, 
tasks: <empty list>, 
ctime: 2:53 PM - October 20, 2022, 
cday: October 20, 2022, 
mtime: 2:54 PM - October 20, 2022, 
mday: October 20, 2022, 
size: 13, 
starred: false, 
frontmatter: <empty object>, 
ext: md.
```

**Field-name examples. As in the note versus used in the DVQ\
✅ Note-type::\
✅ Notetype::\
🚫 Note type:: \[\[Screenshot from 2022-10-18 23-58-49.png\]\] **Command
`Where` is sensitive to capital\*\*

**Query example**
Table tags, alias, children, test
WHERE startswith(file.path, "main/Test/")
Sort file.mtime DESC
limit 10
FLATTEN tags
GROUP BY field
WHERE !completed AND file.ctime <= date(today) - dur(1 month)

## Inline
We are on page `= this.file.name`.

## Basic

``` dataview
Table notetype, Name, Phone, Address
From #person
Sort Name descending
```

## Without ID

``` dataview
Table without ID Name As "Full Name", Phone, Address
From #person
Sort Name descending
```

## Calendar

``` dataview
Calendar file.mtime
From "contact"
```

## Where

``` dataview
Table Name, Phone, Address
From #person
Where Name!="John Doe"
Where notetype="#person"
Sort Name descending
```

## List

``` dataview
List
From #person
Where Name!="John Doe"
Sort Name descending
```

## List all files in the current folder

``` dataview
Table file.mtime AS "Last Modified"
WHERE contains(file.folder, this.file.folder)
Sort file.mtime DESC
```

``` dataview
Table file.mtime AS "Last Modified"
WHERE !file.folder
Sort file.mtime DESC
```

## CSV Import

``` dataview
Table Without ID test, gmapping
From csv("/assets/datasheet/slam_compare.csv")
```

``` dataview
Table Project, url, path
From "example/contact"
Sort Name descending
```
