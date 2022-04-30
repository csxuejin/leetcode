package main

import (
	"sort"
	"strings"
)

type folder struct {
	son map[string]*folder
	val string // 文件夹名称
	del bool   // 删除标记
}

func deleteDuplicateFolder(paths [][]string) (ans [][]string) {
	root := &folder{}
	for _, path := range paths {
		// 将 path 加入字典树
		f := root
		for _, s := range path {
			if f.son == nil {
				f.son = map[string]*folder{}
			}
			if f.son[s] == nil {
				f.son[s] = &folder{}
			}
			f = f.son[s]
			f.val = s
		}
	}

	folders := map[string][]*folder{} // 存储括号表达式及其对应的文件夹节点列表
	var dfs func(*folder) string
	dfs = func(f *folder) string {
		if f.son == nil {
			return "(" + f.val + ")"
		}
		expr := make([]string, 0, len(f.son))
		for _, son := range f.son {
			expr = append(expr, dfs(son))
		}
		sort.Strings(expr)
		subTreeExpr := strings.Join(expr, "") // 按字典序拼接所有子树
		folders[subTreeExpr] = append(folders[subTreeExpr], f)
		return "(" + f.val + subTreeExpr + ")"
	}
	dfs(root)

	for _, fs := range folders {
		if len(fs) > 1 { // 将括号表达式对应的节点个数大于 1 的节点全部删除
			for _, f := range fs {
				f.del = true
			}
		}
	}

	// 再次 DFS 这颗字典树，仅访问未被删除的节点，并将路径记录到答案中
	path := []string{}
	var dfs2 func(*folder)
	dfs2 = func(f *folder) {
		if f.del {
			return
		}
		path = append(path, f.val)
		ans = append(ans, append([]string(nil), path...))
		for _, son := range f.son {
			dfs2(son)
		}
		path = path[:len(path)-1]
	}
	for _, son := range root.son {
		dfs2(son)
	}
	return
}
