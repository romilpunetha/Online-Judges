/*!CK:1156341316!*//*1453175262,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["SLzso"]); }

__d('ArticleAuthorEngagementBlock', ['CSS', 'csx', 'DOMQuery', 'Event', 'Style'], function a(b, c, d, e, f, g, h, i, j, k, l) { if (c.__markCompiled) c.__markCompiled(); var m = { registerClickHandler: function (n, o, p) { k.listen(n, 'click', function (q) { if (o !== undefined && h.shown(o) === false) { if (p) { var r = j.scry(n, "._3c21"), s = j.scry(n, "._6m3"); if (r.length === 0 || s.length === 0) return; var t = r[0], u = s[0]; l.set(t, 'height', '237px'); l.set(u, 'height', '179px'); } h.show(o); } }); } }; f.exports = m; }, null);
__d('legacy:nearby-controller', ['NearbyController'], function a(b, c, d, e) { if (c.__markCompiled) c.__markCompiled(); b.NearbyController = c('NearbyController'); }, 3);