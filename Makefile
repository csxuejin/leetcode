deploy:
	tar czvf leetcode.tar.gz _book
	scp leetcode.tar.gz root@wedays:/web/www/leetcode/leetcode.tar.gz
	ssh root@wedays "cd /web/www/leetcode && rm -f /front/* && tar -xvf leetcode.tar.gz && cp -r _book/* front && rm -rf _book && rm -rf leetcode.tar.gz"

