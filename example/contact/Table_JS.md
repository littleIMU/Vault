## Inline JS Expression
This page was last modified at `$= dv.current().file.mtime`.
This page was in `$= dv.current().file.folder`.

## Task view
```dataviewjs
dv.taskList(dv.pages('"example/contact"').file.tasks.where(t => !t.completed));
```

```dataviewjs
dv.taskList(dv.pages("#person").file.tasks.where(t => !t.completed));
```

## Table view
```dataviewjs
// Render a simple table of book info sorted by rating. 
let _limit = 1, a = 5;
dv.table(["File", "Genre", "Time Read", "Rating"], dv.pages("#person") 
// dv.table(["File", "name", "phone", "address"], dv.pages('"example/contact"') 
	.sort(b => b.Name, 'desc')
	.where(a => a.file.folder.endsWith("contact"))
	.map(b => [b.file.link, b.Name, b["time-read"], b.Address])
	.limit(_limit))
```

## List view
```dataviewjs
dv.list([1, 2, 3])

```

## Others
```dataviewjs
dv.paragraph("This is some text");
dv.span("This is some text");
dv.span("This is some text");
dv.paragraph("This is some text");


```






