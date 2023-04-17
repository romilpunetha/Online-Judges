/*!CK:614116508!*//*1453173163,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["A2Xtn"]); }

__d('EgoAdsObjectSet', ['DOM', 'csx'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); function j() { 'use strict'; this._allEgoUnits = []; this._egoUnits = []; } j.prototype.init = function (l) { 'use strict'; this._allEgoUnits = l; this._egoUnits = []; this._allEgoUnits.forEach(function (m) { var n = k(m); if (!n || !n.holdout) this._egoUnits.push(m); }, this); }; j.prototype.getCount = function () { 'use strict'; return this._egoUnits.length; }; j.prototype.forEach = function (l, m) { 'use strict'; this._egoUnits.forEach(l, m); }; j.prototype.getUnit = function (l) { 'use strict'; return this._egoUnits[l]; }; j.prototype.getHoldoutAdIDsForSpace = function (l, m) { 'use strict'; if (!l || !m) return []; var n = []; for (var o = 0; l > 0 && o < this._allEgoUnits.length; o++) { var p = this._allEgoUnits[o], q = m(p), r = k(p); if (l >= q && r && r.holdout) n.push(r.adid); l -= q; } return n; }; j.prototype.getHoldoutAdIDsForNumAds = function (l) { 'use strict'; l = Math.min(l, this._allEgoUnits.length); var m = []; for (var n = 0; n < l; n++) { var o = this._allEgoUnits[n], p = k(o); if (p && p.holdout) m.push(p.adid); } return m; }; function k(l) { var m = h.scry(l, "div._4u8")[0], n = m && m.getAttribute('data-ad'); return n && JSON.parse(n) || undefined; } f.exports = j; }, null);
__d('BookmarkFeedSorter', ['Run'], function a(b, c, d, e, f, g, h) { if (c.__markCompiled) c.__markCompiled(); var i, j = { init: function (k) { i = k; h.onLeave(function () { i = null; }); }, setChecked: function (k) { if (i) i.setValue(k); } }; f.exports = j; }, null);
__d('LitestandStream', ['CSS', 'LitestandStoryInsertionStatus', 'ViewportBounds', 'cx', 'csx', 'getElementPosition', 'nullthrows'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { if (c.__markCompiled) c.__markCompiled(); var o, p, q = { init: function (r, s, t) { o = t; p = r; }, getStoriesSelector: function () { return "._5jmm"; }, getStreamRoot: function () { return p; }, getSectionID: function () { return o; }, isStory: function (r) { return h.hasClass(r, "_5jmm"); }, canInsertNewerStories: function () { if (j.getTop() > m(q.getStreamRoot()).y) return false; return i.canInsert(); }, getFeedStreamID: function () { return parseInt(n(p).id.split('feed_stream_')[1], 16) % 1e+08; } }; f.exports = q; }, null);
__d("Ease", [], function a(b, c, d, e, f, g) { if (c.__markCompiled) c.__markCompiled(); var h = { makePowerOut: function (i) { var j = h.makePowerIn(i); return function (k) { return 1 - j(1 - k); }; }, makePowerIn: function (i) { return function (j) { var k = Math.pow(j, i); return (k * 10000 | 0) / 10000; }; }, makePowerInOut: function (i) { var j = h.makePowerIn(i), k = h.makePowerOut(i); return function (l) { return l < .5 ? .5 * j(l * 2) : .5 * k(l * 2 - 1) + .5; }; }, expoOut: function (i) { return 1 - Math.pow(2, -10 * i); }, expoIn: function (i) { return 1 - h.expoOut(1 - i); }, expoInOut: function (i) { return i < .5 ? .5 * h.expoIn(i * 2) : .5 * h.expoOut(i * 2 - 1) + .5; }, sineOut: function (i) { return Math.sin(i * Math.PI * .5); }, sineIn: function (i) { return 1 - Math.cos(i * Math.PI * .5); }, sineInOut: function (i) { return -.5 * (Math.cos(Math.PI * i) - 1); }, circOut: function (i) { i--; return Math.sqrt(1 - i * i); }, circIn: function (i) { return 1 - h.circOut(1 - i); }, circInOut: function (i) { return i < .5 ? .5 * h.circIn(i * 2) : .5 * h.circOut(i * 2 - 1) + .5; }, bounceOut: function (i) { if (i < 1 / 2.75) { return 7.5625 * i * i; } else if (i < 2 / 2.75) { return 7.5625 * (i -= 1.5 / 2.75) * i + .75; } else if (i < 2.5 / 2.75) { return 7.5625 * (i -= 2.25 / 2.75) * i + .9375; } else return 7.5625 * (i -= 2.625 / 2.75) * i + .984375; }, bounceIn: function (i) { return 1 - h.bounceOut(1 - i); }, bounceInOut: function (i) { return i < .5 ? .5 * h.bounceIn(i * 2) : .5 * h.bounceOut(i * 2 - 1) + .5; }, makeBounceOut: function (i) { i = i || 1; return function (j) { j = (1 - Math.cos(j * Math.PI * i)) * (1 - j) + j; return 1 - Math.abs(1 - j); }; }, makeBounceIn: function (i) { var j = h.makeBounceOut(i); return function (k) { return 1 - j(1 - k); }; }, makeElasticOut: function (i, j) { i < 1 && (i = 1); var k = Math.PI * 2; return function (l) { if (l === 0 || l === 1) return l; var m = j / k * Math.asin(1 / i); return i * Math.pow(2, -10 * l) * Math.sin((l - m) * k / j) + 1; }; }, makeElasticIn: function (i, j) { var k = h.makeElasticOut(i, j); return function (l) { return 1 - k(1 - l); }; }, makeElasticInOut: function (i, j) { j *= 1.5; var k = h.makeElasticIn(i, j), l = h.makeElasticOut(i, j); return function (m) { return m < .5 ? .5 * k(m * 2) : .5 * l(m * 2 - 1) + .5; }; }, makeBackOut: function (i) { var j = h.makeBackIn(i); return function (k) { return 1 - j(1 - k); }; }, makeBackIn: function (i) { return function (j) { return j * j * ((i + 1) * j - i); }; }, makeBackInOut: function (i) { i *= 1.525; var j = h.makeBackIn(i), k = h.makeBackOut(i); return function (l) { return l < .5 ? .5 * j(l * 2) : .5 * k(l * 2 - 1) + .5; }; } }; h.elasticOut = h.makeElasticOut(1, .3); h.elasticIn = h.makeElasticIn(1, .3); h.elasticInOut = h.makeElasticInOut(1, .3); h.backOut = h.makeBackOut(1.7); h.backIn = h.makeBackIn(1.7); h.backInOut = h.makeBackInOut(1.7); f.exports = h; }, null);
__d('SelectorDeprecated', ['Arbiter', 'Button', 'ContextualLayer', 'CSS', 'DataStore', 'DOM', 'Event', 'Focus', 'HTML', 'Keys', 'MenuDeprecated', 'Parent', 'Style', 'Toggler', 'TooltipData', 'URI', 'Vector', 'arrayContains', 'emptyFunction', 'getDocumentScrollElement'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, aa) { if (c.__markCompiled) c.__markCompiled(); var ba, ca, da = [], ea; function fa(qa) { return s.byClass(qa, 'uiSelector'); } function ga(qa) { return s.byClass(qa, 'uiSelectorButton'); } function ha() { if (!ca) { ca = new j({ position: 'below' }, m.create('div')); k.addClass(ca.getRoot(), 'uiSelectorContextualLayer'); } return ca; } function ia(qa) { return m.scry(qa, 'select')[0]; } function ja(qa) { return m.find(qa, 'div.uiSelectorMenuWrapper'); } var ka = function () { ka = z; r.subscribe('select', function (qa, ra) { if (!ba || !ra || ra.menu !== pa.getSelectorMenu(ba)) return; var sa = la(ba), ta = ma(ra.item); if (ta) { var ua = ba, va = pa.isOptionSelected(ra.item), wa = pa.inform('select', { selector: ua, option: ra.item, clone: ea }); if (wa === false) return; if (sa || !va) { pa.setSelected(ua, pa.getOptionValue(ra.item), !va); pa.inform('toggle', { selector: ua, option: ra.item }); pa.inform('change', { selector: ua }); h.inform('Form/change', { node: ua }); if (na(ua)) l.set(ua, 'dirty', true); } } if (!sa || !ta) ba && pa.toggle(ba); }); }; function la(qa) { return !!qa.getAttribute('data-multiple'); } function ma(qa) { return k.hasClass(qa, 'uiSelectorOption'); } function na(qa) { return !!qa.getAttribute('data-autosubmit'); } var oa = function () { oa = z; var qa = { keydown: function (event) { var ra = event.getTarget(); if (m.isInputNode(ra)) return; switch (n.getKeyCode(event)) { case q.DOWN: case q.SPACE: case q.UP: if (ga(ra)) { var sa = fa(ra); pa.toggle(sa); return false; } break; case q.ESC: if (ba) { var ta = pa.getSelectorButton(ba); pa.toggle(ba); ta && o.set(ta); return false; } break; } }, mouseover: function (event) { var ra = s.byAttribute(event.getTarget(), 'ajaxify'); if (ra && k.hasClass(ra, 'uiSelectorButton')) pa.loadMenu(fa(ra)); } }; n.listen(document.body, qa); }; u.subscribe(['show', 'hide'], function (qa, ra) { var sa = fa(ra.getActive()); if (sa) { oa(); ka(); var ta = pa.getSelectorButton(sa), ua = pa.getSelectorMenu(sa), va = qa === 'show'; ta.setAttribute('aria-expanded', va ? 'true' : 'false'); if (va) { ba = sa; if (k.hasClass(ta, 'uiButtonDisabled')) { pa.setEnabled(sa, false); return false; } ua = ua || pa.loadMenu(sa); var wa = t.getScrollParent(sa), xa = wa !== window && wa !== aa(); if (xa || k.hasClass(sa, 'uiSelectorUseLayer')) { if (xa) da.push(n.listen(wa, 'scroll', function () { ra.hide(); })); ea = m.create('div', { className: sa.className }); k.addClass(ea, 'invisible_elem'); x.getElementDimensions(sa).setElementDimensions(ea); m.replace(sa, ea); var ya = k.hasClass(sa, 'uiSelectorRight'), za = k.hasClass(sa, 'uiSelectorBottomUp'); ha().setContext(ea).setContent(sa).setPosition(za ? 'above' : 'below').setAlignment(ya ? 'right' : 'left').show(); } r.register(ua); var ab = r.getCheckedItems(ua); if (!ab.length) ab = r.getEnabledItems(ua); if (ab.length) r.focusItem(ab[0]); } else { ba = null; if (ea) { while (da.length) da.pop().remove(); m.replace(ea, sa); ha().hide(); ea = null; } ua && r.unregister(ua); if (na(sa) && l.get(sa, 'dirty')) { var bb = m.scry(sa, 'input.submitButton')[0]; bb && bb.click(); l.remove(sa, 'dirty'); } } k.conditionClass(pa.getSelectorButton(sa), 'selected', va); pa.inform(va ? 'open' : 'close', { selector: sa, clone: ea }); } }); var pa = Object.assign(new h(), { attachMenu: function (qa, ra, sa) { qa = fa(qa); if (qa) { ba && r.unregister(pa.getSelectorMenu(ba)); m.setContent(ja(qa), ra); ba && r.register(pa.getSelectorMenu(qa)); ea && ha().updatePosition(); if (sa) { var ta = qa.getAttribute('data-name'); ta && sa.setAttribute('name', ta); if (!la(qa)) sa.setAttribute('multiple', false); var ua = ia(qa); if (ua) { m.replace(ua, sa); } else m.insertAfter(qa.firstChild, sa); } return true; } }, getOption: function (qa, ra) { var sa = pa.getOptions(qa), ta = sa.length; while (ta--) if (ra === pa.getOptionValue(sa[ta])) return sa[ta]; return null; }, getOptions: function (qa) { var ra = r.getItems(pa.getSelectorMenu(qa)); return ra.filter(ma); }, getEnabledOptions: function (qa) { var ra = r.getEnabledItems(pa.getSelectorMenu(qa)); return ra.filter(ma); }, getSelectedOptions: function (qa) { return r.getCheckedItems(pa.getSelectorMenu(qa)); }, getOptionText: function (qa) { return r.getItemLabel(qa); }, getOptionValue: function (qa) { var ra = fa(qa), sa = ia(ra), ta = pa.getOptions(ra).indexOf(qa); return ta >= 0 ? sa.options[ta + 1].value : ''; }, getSelectorButton: function (qa) { return m.find(qa, 'a.uiSelectorButton'); }, getSelectorMenu: function (qa) { return m.scry(qa, 'div.uiSelectorMenu')[0]; }, getValue: function (qa) { var ra = ia(qa); if (!ra) return null; if (!la(qa)) return ra.value; var sa = [], ta = ra.options; for (var ua = 1, va = ta.length; ua < va; ua++)if (ta[ua].selected) sa.push(ta[ua].value); return sa; }, isOptionSelected: function (qa) { return r.isItemChecked(qa); }, listen: function (qa, ra, sa) { return this.subscribe(ra, function (ta, ua) { if (ua.selector === qa) return sa(ua, ta); }); }, loadMenu: function (qa, ra) { var sa = pa.getSelectorMenu(qa); if (!sa) { var ta = pa.getSelectorButton(qa), ua = ta.getAttribute('ajaxify'); if (ua) { e(['AsyncRequest'], (function (wa) { var xa = new w(ua), ya = xa.getQueryData(); xa.setQueryData({}); var za = new wa(xa).setData(ya).setNectarModuleDataSafe(ta).setRelativeTo(ta); ra && za.setFinallyHandler(function () { setTimeout(ra, 0); }); za.send(); }).bind(this)); var va = p('<div class="uiSelectorMenuWrapper uiToggleFlyout">' + '<div class="uiMenu uiSelectorMenu loading">' + '<ul class="uiMenuInner">' + '<li><span></span></li>' + '</ul>' + '</div>' + '</div>'); m.appendContent(ta.parentNode, va); sa = pa.getSelectorMenu(qa); ta.removeAttribute('onmouseover'); } } else ra && ra(); return sa; }, setButtonLabel: function (qa, ra) { var sa = pa.getSelectorButton(qa), ta = parseInt(sa.getAttribute('data-length'), 10); ra = ra || sa.getAttribute('data-label') || ''; i.setLabel(sa, ra); if (typeof ra === 'string') if (ta && ra.length > ta) { sa.setAttribute('title', ra); } else sa.removeAttribute('title'); }, setButtonTooltip: function (qa, ra) { var sa = pa.getSelectorButton(qa), ta = s.byTag(sa, 'a'); ta && v.set(ta, ra || sa.getAttribute('data-tooltip') || ''); }, setEnabled: function (qa, ra) { if (!ra && ba && fa(qa) === ba) pa.toggle(qa); i.setEnabled(pa.getSelectorButton(qa), ra); }, setOptionEnabled: function (qa, ra) { r.setItemEnabled(qa, ra); }, setSelected: function (qa, ra, sa) { sa = sa !== false; var ta = pa.getOption(qa, ra); if (!ta) return; var ua = pa.isOptionSelected(ta); if (sa !== ua) { if (!la(qa) && !ua) { var va = pa.getSelectedOptions(qa)[0]; va && r.toggleItem(va); } r.toggleItem(ta); } pa.updateSelector(qa); }, toggle: function (qa) { u.toggle(m.scry(fa(qa), 'div.wrap')[0]); }, updateSelector: function (qa) { var ra = pa.getOptions(qa), sa = pa.getSelectedOptions(qa), ta = ia(qa).options, ua = [], va = []; for (var wa = 0, xa = ra.length; wa < xa; wa++) { var ya = y(sa, ra[wa]); ta[wa + 1].selected = ya; if (ya) { var za = pa.getOptionText(ra[wa]); ua.push(za); va.push(ra[wa].getAttribute('data-tooltip') || za); } } ta[0].selected = !sa.length; var ab = k.hasClass(qa, 'uiSelectorDynamicLabel'), bb = k.hasClass(qa, 'uiSelectorDynamicTooltip'); if (ab || bb) { var cb = ''; if (la(qa)) { var db = pa.getSelectorButton(qa); cb = db.getAttribute('data-delimiter') || ', '; } ua = ua.join(cb); va = va.join(cb); ab && pa.setButtonLabel(qa, ua); bb && pa.setButtonTooltip(qa, va); } } }); f.exports = pa; }, null);