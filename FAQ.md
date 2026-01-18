# Frequently Asked Questions(FAQ)

## 我无法移除已失效的目录？
报错中应当含有[time]E:路径不存在:path，两种方法：
1. 在ypts的目录下找到路径data/inpaths.ypts，以文本格式打开，删除其中的path条目，保存并重启ypts。（将“path”替换为实际值）
2. 重新建立path路径，并运行移除命令 `ypts rm-path path` （将“path”替换为实际值）

## 