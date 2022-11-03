```dataviewjs
// Render a simple table of action info sorted by created time. 
let _limit = 10, _order = 'desc';
dv.table(["File","Status","Project","LastEdited"], dv.pages('"main/course"') 
	.sort(b => b.file.mtime, _order)
	.where(a => a.file.folder.endsWith("course"))
	.map(b => [b.file.link, b.status, b.link_project, b.file.mtime])
	.limit(_limit))
```
