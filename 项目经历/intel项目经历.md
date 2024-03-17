
Intel QAT卡。
在SPR后被集成进志强处理器。

加解密：明星项目。 Async-Nginx, qatengine. udp-nginx

压缩解压缩：
自己主做项目：
QAT-ZSTD-Plugin： 集成ZSTD和QAT。将字典编码卸载到QAT卡上进行运算。共同探索和讨论决定使用回调的方式进行集成。
一开始准备集成在内部。后来发现可行性和可维护性较低。
在未来，在DMR上会全面支持zstd的压缩和解压缩。
反响很好。

QATzip: 基于QAT的高性能压缩库。
支持deflate，lz4等格式


其余还有一些应用的集成。
RocksDB: 一种是通过compressor，已经开源。 可以集成qatzip和qat-zstd-plugin
另一种就是直接改rocksdb

ceph, mongodb, 大数据， go-qat, jni, redis. nginx, envoy.
只要需要用到压缩的地方，都可以使用qat。
其实还可以做的还有很多，比如lz4原生库的支持，Rust的支持。

客户主要有meta，阿里，字节，腾讯，百度，h3c




问题：

1. deflate压缩算法原理

2. lz4压缩算法原理

3. zstd压缩算法原理

4. instance如何解决竞争问题（原子操作）

5. 可优化方向：polling时机。是否可以使用事件循环机制？

QATzip: 基于用户态库的压缩库。供上层应用调用。
支持deflate， lz4压缩格式。支持lz4s+postprocessing。下一代会支持zstd。
为什么有驱动还要做qatzip库？
因为需要配置的资源很多。用户集成麻烦。
方便用户使用。

并行

zero copy

不同线程可以共享instance

基于异步处理模式，提供同步的压缩接口




