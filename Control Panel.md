# Latest notes

```dataviewjs
// Render a simple table of action info sorted by created time. 
let _limit = 10, _order = 'desc';
dv.table(["File","Status","Category","LastEdited"], dv.pages('"main"') 
	.sort(b => b.file.mtime, _order)
	//.where(a => a.file.folder.endsWith("main"))
	.map(b => [b.file.link, b.status, b.file.folder, b.file.mtime])
	.limit(_limit))
```

# Recent  Todos
```dataviewjs
dv.taskList(dv.pages('"main"').file.tasks
	.where(t => t.text.includes("#Todo"))
	.limit(10))
```

# Recent Questions
```dataviewjs
dv.taskList(dv.pages('"main"').file.tasks
	.where(t => t.text.includes("#Ques"))
	.limit(10))
```