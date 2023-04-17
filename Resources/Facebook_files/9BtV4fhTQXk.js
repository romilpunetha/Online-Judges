/*!CK:3562005256!*//*1453173163,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["pubPN"]); }

__d('CenteredContainer.react', ['React', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j) { if (c.__markCompiled) c.__markCompiled(); var k = h.PropTypes, l = h.createClass({ displayName: 'CenteredContainer', propTypes: { fullHeight: k.bool, vertical: k.bool, horizontal: k.bool }, getDefaultProps: function () { return { fullHeight: false, vertical: false, horizontal: true }; }, render: function () { var m = (this.props.vertical ? "_3bwv" : '') + (this.props.horizontal ? ' ' + "_3bww" : ''), n = h.Children.map(this.props.children, function (p) { return (h.createElement('div', { className: "_3bwx" }, p)); }), o = j(this.props.className, this.props.fullHeight ? "_5bpf" : ''); return (h.createElement('div', babelHelpers._extends({}, this.props, { className: o }), h.createElement('div', { className: m }, h.createElement('div', { className: "_3bwy" }, n)))); } }); f.exports = l; }, null);
__d('getDOMImageSize', ['EncryptedImg', 'URI'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); function j(o) { o.onload = null; o.onerror = null; o.onreadystatechange = null; o._callback = null; o._thisObj = null; o._srcStr = null; o.parentNode && o.parentNode.removeChild(o); } function k() { var o = this; if (o._callback) o._callback.call(o._thisObj, o.naturalWidth || o.width, o.naturalHeight || o.height, o._srcStr); j(o); } function l() { var o = this; if (o.readyState === 'complete') k.call(o); } function m() { var o = this; if (o._callback) o._callback.call(o._thisObj, 0, 0, o._srcStr); j(o); } function n(o, p, q) { q = q || null; if (!o) { p.call(q, 0, 0, ''); return; } var r = document.body; if (!r) { setTimeout(n.bind(this, o, p, q), 500); return; } var s; if (typeof o === 'string') { s = o; } else if (typeof o === 'object') if (typeof o.width === 'number' && typeof o.height === 'number') { if (typeof o.src === 'string') { s = o.src; if (o.naturalWidth && o.naturalHeight) { p.call(q, o.naturalWidth, o.naturalHeight, s); return; } } if (typeof o.uri === 'string') { s = o.uri; if (o.width && o.height) { p.call(q, o.width, o.height, s); return; } } } else if (o instanceof i) s = o.toString(); if (!s) { p(0, 0, o); return; } var t = document.createElement('img'); t.onreadystatechange = l; t.onload = k; t.onerror = m; t._callback = p; t._thisObj = q; t._srcStr = s; if (h.isEncrypted(s)) { h.insertIntoDOM(s, t); } else t.src = s; t.style.cssText = '\n    position:absolute;\n    left:-5000px;\n    top:-5000px;\n    width:auto;\n    height:auto;\n    clip:rect(0 0 0 0);\n  '.replace(/\s+/, ' '); r.insertBefore(t, r.firstChild); } f.exports = n; }, null);
__d('CachedDOMImageSizePool', ['debounce', 'getDOMImageSize'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); function j(k, l) { 'use strict'; this.$CachedDOMImageSizePool1 = {}; this.$CachedDOMImageSizePool2 = l; this.$CachedDOMImageSizePool3 = 0; this.$CachedDOMImageSizePool4 = k; this.$CachedDOMImageSizePool5 = h(this.$CachedDOMImageSizePool6, 5000, this); this.$CachedDOMImageSizePool7 = {}; this.$CachedDOMImageSizePool8 = {}; } j.prototype.get = function (k, l, m) { 'use strict'; if (!k) { l.call(m, 0, 0, k); return; } var n = this.$CachedDOMImageSizePool1[k]; if (n) { n.lastAccessTime = Date.now(); l.call(m, n.width, n.height, n.src); } else if (this.$CachedDOMImageSizePool7[k]) { this.$CachedDOMImageSizePool7[k].push(l); this.$CachedDOMImageSizePool8[k].push(m); } else { this.$CachedDOMImageSizePool7[k] = [l]; this.$CachedDOMImageSizePool8[k] = [m]; i(k, this.$CachedDOMImageSizePool9, this); } }; j.prototype.set = function (k, l, m) { 'use strict'; if (this.$CachedDOMImageSizePool3 > this.$CachedDOMImageSizePool4) this.$CachedDOMImageSizePool5(); var n = this.$CachedDOMImageSizePool1; if (k && !n[k]) { var o = { width: l, height: m, src: k, lastAccessTime: Date.now() }; n[k] = o; this.$CachedDOMImageSizePool3++; } }; j.prototype.$CachedDOMImageSizePool9 = function (k, l, m) { 'use strict'; this.set(m, k, l); var n = this.$CachedDOMImageSizePool7[m], o = this.$CachedDOMImageSizePool8[m]; for (var p = 0, q = n.length; p < q; p++)n[p].call(o[p], k, l, m); delete this.$CachedDOMImageSizePool7[m]; delete this.$CachedDOMImageSizePool8[m]; }; j.prototype.$CachedDOMImageSizePool6 = function () { 'use strict'; var k = Date.now(), l = this.$CachedDOMImageSizePool1, m = this.$CachedDOMImageSizePool3, n = this.$CachedDOMImageSizePool2; for (var o in l) { var p = l[o]; if (k - p.lastAccessTime > n) { delete l[o]; m--; } } this.$CachedDOMImageSizePool3 = m; }; f.exports = j; }, null);
__d('BackgroundImage.react', ['CachedDOMImageSizePool', 'Image.react', 'React', 'XUISpinner.react', 'cx', 'invariant', 'joinClasses', 'clamp'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o) { if (c.__markCompiled) c.__markCompiled(); var p = j.PropTypes, q = '(-?(\\d+\\.)?\\d+(px|\\%))', r = new RegExp('^' + q + '?(\\s' + q + ')?$', 'g'), s = new h(50, 10 * 60 * 1000), t = j.createClass({ displayName: 'BackgroundImage', propTypes: { src: p.string, width: p.number.isRequired, height: p.number.isRequired, backgroundSize: p.oneOf(['contain', 'cover', 'containinside', 'coverinside']), loadingIndicatorStyle: p.oneOf(['none', 'large', 'small']), backgroundPosition: function (u, v, w) { var x = u[v]; if (x) { !(typeof x === 'string') ? m(0) : undefined; !x.match(r) ? m(0) : undefined; } !(u.backgroundFocus == null || u.backgroundPosition == null) ? m(0) : undefined; }, backgroundFocus: function (u, v, w) { var x = u[v]; if (x) { !(typeof x === 'string') ? m(0) : undefined; !x.match(r) ? m(0) : undefined; } !(u.backgroundFocus == null || u.backgroundPosition == null) ? m(0) : undefined; }, onImageLoad: p.func, optimizeResizeSpeed: p.bool, onContextMenu: p.func }, getInitialState: function () { return { imageWidth: null, imageHeight: null, imageSrc: this.props.src, loading: true }; }, getDefaultProps: function () { return { optimizeResizeSpeed: false, loadingIndicatorStyle: 'none' }; }, componentDidMount: function () { this._resolveImageSize(); }, componentDidUpdate: function (u) { if (this.props.src !== this.state.imageSrc) this.setState({ imageWidth: 0, imageHeight: 0, imageSrc: this.props.src, loading: true }, this._resolveImageSize); }, _resolveImageSize: function () { var u = this.state.imageSrc; if (u) s.get(u, this._onImageSizeResolved, this); }, render: function () { var u = { width: this.props.width + 'px', height: this.props.height + 'px' }, v = n(this.props.className, "_5f0d"); return (j.createElement('div', babelHelpers._extends({}, this.props, { className: n(this.props.className, v), style: babelHelpers._extends({}, this.props.style || {}, u), onContextMenu: this.props.onContextMenu }), this._renderImage(), this._renderContent(), this._renderLoadingIndicator())); }, _renderLoadingIndicator: function () { if (!this.state.loading || this.props.loadingIndicatorStyle === 'none') return null; return (j.createElement('div', { className: "_1qe- _5lar" }, j.createElement('div', { className: "_1qe_" }, j.createElement('div', { className: "_1qf0" }, j.createElement(k, { size: this.props.loadingIndicatorStyle }))))); }, _renderContent: function () { if (this.props.children) return (j.createElement('div', { className: "_1qe-" }, j.createElement('div', { className: "_1qe_" }, j.createElement('div', { className: "_1qf0" }, this.props.children)))); }, _renderImage: function () { if (!this.state.imageWidth || !this.state.imageHeight) return; var u = this.props.width, v = this.props.height, w, x; switch (this.props.backgroundSize) { case 'cover': w = 'cover'; x = false; break; case 'coverinside': w = 'cover'; x = true; break; case 'contain': w = 'contain'; x = false; break; case 'containinside': w = 'contain'; x = true; }var y = this.state.imageWidth, z = this.state.imageHeight, aa = u / v, ba = y / z; if (w === 'contain') if ((y > u || !x) && ba >= aa) { y = u; z = y / ba; } else if (z > v || !x) { z = v; y = z * ba; } if (w === 'cover') if ((y > u || !x) && ba >= aa) { z = v; y = z * ba; } else if (z > v || !x) { y = u; z = y / ba; } var ca = this._getImageStyle(y, z); return (j.createElement(i, { alt: '', className: "_5i4g" + (this.props.optimizeResizeSpeed ? ' ' + "_5sjv" : ''), style: ca, src: this.state.imageSrc })); }, _getImageStyle: function (u, v) { var w = ['50%', '50%'], x = this._getBackgroundPositionPxValue; if (this.props.backgroundPosition) { w = this.props.backgroundPosition.split(' '); } else if (this.props.backgroundFocus) { w = this.props.backgroundFocus.split(' '); x = this._getBackgroundFocusPxValue; } return { width: Math.round(u) + 'px', height: Math.round(v) + 'px', left: x(w[0], u, this.props.width), top: x(w[1] || w[0], v, this.props.height) }; }, _getBackgroundPositionPxValue: function (u, v, w) { var x = parseFloat(u), y = u.substr(x.toString().length); if (y === 'px') return u; return Math.round((w - v) * (x / 100)) + 'px'; }, _getBackgroundFocusPxValue: function (u, v, w) { var x = parseFloat(u), y = u.substr(x.toString().length); if (v < w) return '0'; var z = y === 'px' ? x : Math.round(v * (x / 100)), aa = z - w / 2; aa = o(aa, 0, v - w); return -aa + 'px'; }, _onImageSizeResolved: function (u, v, w) { if (!this.isMounted() || this.state.imageSrc !== w) return; var x = this.props.onImageLoad ? this.props.onImageLoad.bind(null, u, v) : null; this.setState({ imageWidth: u, imageHeight: v, loading: false }, x); } }); f.exports = t; }, null);
__d('PopoverMenu.react', ['CSS', 'InlineBlock.react', 'Popover', 'PopoverMenu', 'React', 'ReactDOM', 'ReactElement', 'SubscriptionsHandler', 'cx', 'joinClasses', 'areEqual', 'setImmediate'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) { if (c.__markCompiled) c.__markCompiled(); var t = l.PropTypes, u = l.createClass({ displayName: 'ReactPopoverMenu', statics: { getFirstChild: function (v) { var w = v.children; return Array.isArray(w) ? w[0] : w; }, getButtonSize: function (v) { var w = u.getFirstChild(v); return w && w.type.getButtonSize(w.props); } }, propTypes: { alignh: t.oneOf(['left', 'center', 'right']), alignv: t.oneOf(['baseline', 'bottom', 'middle', 'top']), position: t.oneOf(['above', 'below', 'left', 'right']), layerBehaviors: t.array, menu: t.object.isRequired, disabled: t.bool }, getDefaultProps: function () { return { alignv: 'middle' }; }, _menuSubscriptions: null, componentDidMount: function () { var v = m.findDOMNode(this.refs.root), w = v.firstChild; h.addClass(w, "_p"); this._popover = new j(v, w, this.props.layerBehaviors, { alignh: this.props.alignh, position: this.props.position, disabled: this.props.disabled, arrowDimensions: { offset: 0, length: 0 } }); this._popoverMenu = new k(this._popover, w, this._createMenu(this.props.menu), this.props.behaviors); }, componentDidUpdate: function (v) { if (!r(v.menu, this.props.menu)) s(this._recreateMenu); if (this.props.alignh !== v.alignh) this._popoverMenu.getPopover().getLayer().setAlignment(this.props.alignh); if (this.props.disabled !== v.disabled) if (this.props.disabled) { this._popoverMenu.disable(); } else this._popoverMenu.enable(); }, _recreateMenu: function () { if (this._menuSubscriptions) { this._menuSubscriptions.release(); this._menuSubscriptions = null; } this._unmountCurrentMenuItems(); this._popoverMenu.setMenu(this._createMenu(this.props.menu)); }, render: function () { var v = l.Children.map(this.props.children, function (w, x) { if (x === 0) { return n.cloneAndReplaceProps(w, babelHelpers._extends({}, w.props, { className: q(w.props.className, "_p") })); } else return w; }); return (l.createElement(i, babelHelpers._extends({}, this.props, { className: q(this.props.className, "uiPopover"), ref: 'root', disabled: null }), v)); }, componentWillUnmount: function () { this.hidePopover(); if (this._menuSubscriptions) { this._menuSubscriptions.release(); this._menuSubscriptions = null; } this._popoverMenu && this._popoverMenu.destroy(); }, _createMenu: function (v) { var w = v.props, x = new v.type(w); this._menuSubscriptions = new o(); if (w.onItemClick) this._menuSubscriptions.addSubscriptions(x.subscribe('itemclick', w.onItemClick)); if (w.onItemFocus) this._menuSubscriptions.addSubscriptions(x.subscribe('focus', w.onItemFocus)); if (w.onItemBlur) this._menuSubscriptions.addSubscriptions(x.subscribe('blur', w.onItemBlur)); if (w.onChange) this._menuSubscriptions.addSubscriptions(x.subscribe('change', w.onChange)); if (this.props.onShow) this._menuSubscriptions.addSubscriptions(this._popover.subscribe('show', this.props.onShow)); if (this.props.onHide) this._menuSubscriptions.addSubscriptions(this._popover.subscribe('hide', this.props.onHide)); return x; }, getMenu: function () { return this._popoverMenu.getMenu(); }, showPopover: function (v) { this._popover.showLayer(); if (v) { var w = this._popoverMenu.getMenu(); w.blur(); w.focusAnItem(v); } }, hidePopover: function () { var v = this._popover; if (v && v.isShown()) v.hideLayer(); }, getFocusedItem: function () { var v = this._popoverMenu.getMenu(); return v.getFocusedItem(); }, _unmountCurrentMenuItems: function () { var v = this.getMenu(); v && v.forEachItem(function (w) { var x = w.getRoot().firstElementChild; x && m.unmountComponentAtNode(x); }); } }); f.exports = u; }, null);
/**
 * @generated SignedSource<<623c7cbcff19956af736c3d064fc689d>>
 *
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !! This file is a check-in of a static_upstream project!      !!
 * !!                                                            !!
 * !! You should not modify this file directly. Instead:         !!
 * !! 1) Use `fjs use-upstream` to temporarily replace this with !!
 * !!    the latest version from upstream.                       !!
 * !! 2) Make your changes, test them, etc.                      !!
 * !! 3) Use `fjs push-upstream` to copy your changes back to    !!
 * !!    static_upstream.                                        !!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 * Copyright (C) 2010 by Johannes Baagoe <baagoe@baagoe.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @providesModule Alea
 * @preserve-header
 */__d('Alea', [], function a(b, c, d, e, f, g) { if (c.__markCompiled) c.__markCompiled(); function h() { var j = 4022871197, k = function (l) { l = l.toString(); for (var m = 0; m < l.length; m++) { j += l.charCodeAt(m); var o = .02519603282416938 * j; j = o >>> 0; o -= j; o *= j; j = o >>> 0; o -= j; j += o * 4294967296; } return (j >>> 0) * 2.3283064365386963e-10; }; k.version = 'Mash 0.9'; return k; } function i() { return (function (j) { var k = 0, l = 0, m = 0, n = 1; if (j.length === 0) j = [new Date()]; var o = new h(); k = o(' '); l = o(' '); m = o(' '); for (var p = 0; p < j.length; p++) { k -= o(j[p]); if (k < 0) k += 1; l -= o(j[p]); if (l < 0) l += 1; m -= o(j[p]); if (m < 0) m += 1; } o = null; var q = function () { var r = 2091639 * k + n * 2.3283064365386963e-10; k = l; l = m; m = r - (n = r | 0); return m; }; q.version = 'Alea 0.9'; q.args = j; return q; })(Array.prototype.slice.call(arguments)); } f.exports = i; }, null);
__d('Random', ['Alea', 'ServerNonce'], function a(b, c, d, e, f, g, h) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var i = 4294967296, j = c('ServerNonce').ServerNonce, k = h(j), l = { random: function () { if (typeof window !== 'undefined' && typeof Uint32Array !== 'undefined') { var m = new Uint32Array(1); if (window.crypto && window.crypto.getRandomValues) { return window.crypto.getRandomValues(m)[0] / i; } else if (window.msCrypto && window.msCrypto.getRandomValues) return window.msCrypto.getRandomValues(m)[0] / i; } return k(); }, uint32: function () { return Math.floor(this.random() * i); } }; f.exports = l; }, null);
__d('MenuItemNoAction', ['MenuItem'], function a(b, c, d, e, f, g, h) { if (c.__markCompiled) c.__markCompiled(); var i, j; i = babelHelpers.inherits(k, h); j = i && i.prototype; k.prototype.hasAction = function () { 'use strict'; return false; }; function k() { 'use strict'; i.apply(this, arguments); } f.exports = k; }, null);
__d('ReactMenu', ['Menu', 'MenuItem', 'MenuItemNoAction', 'MenuSelectableItem', 'MenuTheme', 'ReactChildren', 'SelectableMenu', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) { if (c.__markCompiled) c.__markCompiled(); var q, r, s, t; function u(y) { var z = []; m.forEach(y, function (aa) { if (aa) z.push(aa); }); return z; } function v(y) { y.isReactLegacyFactory = {}; y.type = y; } q = babelHelpers.inherits(w, h); r = q && q.prototype; function w(y, z) { 'use strict'; var aa = babelHelpers._extends({ theme: l, maxheight: y ? y.maxheight : null, className: y ? y.className : null }, z); r.constructor.call(this, u(y.children), aa); } v(w); s = babelHelpers.inherits(x, n); t = s && s.prototype; function x(y, z) { 'use strict'; var aa = babelHelpers._extends({ className: p("_57di", y ? y.className : null), theme: l, multiple: y && y.multiple, maxheight: y ? y.maxheight : null }, z); t.constructor.call(this, u(y.children), aa); } v(x); w.SelectableMenu = x; v(i); w.Item = i; w.ItemNoAction = j; v(k); w.SelectableItem = k; f.exports = w; }, null);
__d('ReactXUIMenu', ['ReactMenu', 'XUIMenuTheme', 'XUIMenuWithSquareCorner'], function a(b, c, d, e, f, g, h, i, j) { if (c.__markCompiled) c.__markCompiled(); var k, l, m, n; function o(r) { r.isReactLegacyFactory = {}; r.type = r; } k = babelHelpers.inherits(p, h); l = k && k.prototype; function p(r) { 'use strict'; var s = { theme: i }; if (!r || r.withsquarecorner !== false) s.behaviors = [j]; l.constructor.call(this, r, s); } o(p); m = babelHelpers.inherits(q, h.SelectableMenu); n = m && m.prototype; function q(r) { 'use strict'; var s = { theme: i }; if (!r || r.withsquarecorner !== false) s.behaviors = [j]; n.constructor.call(this, r, s); } o(q); p.SelectableMenu = q; p.Item = h.Item; p.SelectableItem = h.SelectableItem; f.exports = p; }, null);
__d('UFIOrderingModeSelector.react', ['BanzaiLogger', 'InlineBlock.react', 'Link.react', 'React', 'Image.react', 'Random', 'ReactXUIMenu', 'PopoverMenu.react', 'UFIConfig', 'cx', 'ix'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) { if (c.__markCompiled) c.__markCompiled(); var s = k.PropTypes, t = n.SelectableMenu, u = n.SelectableItem, v = k.createClass({ displayName: 'UFIOrderingModeSelector', propTypes: { onOrderChanged: s.func, feedback: s.shape({ orderingmodes: s.array.isRequired, commentstargetfbid: s.string.isRequired, ownerid: s.string.isRequired }).isRequired }, getInitialState: function () { var w = null; this.props.feedback.orderingmodes.map(function (x) { if (x.selected) w = x; }); return { selectedMode: w }; }, onMenuItemClick: function (w, x) { var y = x.item.getValue(); if (this.props.feedback.orderingmodes && p.logChangeOrderingModeUsageSampleRate > m.random()) h.log('CommentsOrderingModeSelectorUsageLoggerConfig', { start_order: this.state.selectedMode.value, end_order: y, post_fbid: this.props.feedback.commentstargetfbid, post_owner_fbid: this.props.feedback.ownerid, available_orders: this.props.feedback.orderingmodes.map(function (z) { return z.value; }) }); this.props.feedback.orderingmodes.map((function (z) { if (z.value === y) this.setState({ selectedMode: z }); }).bind(this)); this.props.onOrderChanged(y); }, render: function () { var w = k.createElement(t, { className: "_4tju", onItemClick: this.onMenuItemClick }, this.props.feedback.orderingmodes.map((function (x) { return (k.createElement(u, { key: x.value, value: x.value, label: x.name, selected: x.value === this.state.selectedMode.value }, k.createElement('div', { className: "_3scm" }, k.createElement('div', { className: "_3scn" }, x.name), k.createElement('div', { className: "_3sco" }, x.description)))); }).bind(this))); return (k.createElement('div', { className: "_3scp" }, k.createElement(i, null, k.createElement(o, { className: "_3scs", menu: w, alignh: 'right' }, k.createElement(j, null, this.state.selectedMode.name, k.createElement(l, { className: "_3sct", src: r('/images/ui/xhp/link/more/down_caret.gif') })))))); } }); f.exports = v; }, null);
__d('InputLabel.react', ['React', 'cx', 'invariant', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = h.PropTypes, m = 0; function n() { return 'js_input_label_' + m++; } var o = h.createClass({ displayName: 'InputLabel', propTypes: { display: l.oneOf(['block', 'inline']) }, getDefaultProps: function () { return { display: 'block' }; }, render: function () { !(this.props.children.length === 2) ? j(0) : undefined; var p = this.props.children[0], q = this.props.children[1], r = p.type === 'input'; p = h.cloneElement(p, { className: k(p.props.className, "uiInputLabelInput" + (r && p.props.type === 'radio' ? ' ' + "uiInputLabelRadio" : '') + (r && p.props.type === 'checkbox' ? ' ' + "uiInputLabelCheckbox" : '')), id: p.props.id || n() }); q = h.cloneElement(q, { className: k(q.props.className, 'uiInputLabelLabel'), htmlFor: p.props.id }); var s = "uiInputLabel" + (' ' + "clearfix") + (this.props.display === 'inline' ? ' ' + "inlineBlock" : '') + (r ? ' ' + "uiInputLabelLegacy" : ''); return (h.createElement('div', babelHelpers._extends({}, this.props, { className: k(this.props.className, s) }), p, q)); } }); f.exports = o; }, null);
__d('PopoverMenuContextMinWidth', ['CSS', 'Style', 'cx', 'shield'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); function l(m) { 'use strict'; this._popoverMenu = m; this._popover = m.getPopover(); } l.prototype.enable = function () { 'use strict'; this._setMenuSubscription = this._popoverMenu.subscribe('setMenu', k(this._onSetMenu, this)); }; l.prototype.disable = function () { 'use strict'; this._setMenuSubscription.unsubscribe(); this._setMenuSubscription = null; if (this._showSubscription) { this._showSubscription.unsubscribe(); this._showSubscription = null; } if (this._menuSubscription) { this._menuSubscription.unsubscribe(); this._menuSubscription = null; } }; l.prototype._onSetMenu = function () { 'use strict'; this._menu = this._popoverMenu.getMenu(); this._showSubscription = this._popover.subscribe('show', k(this._updateWidth, this)); var m = this._updateWidth.bind(this); this._menuSubscription = this._menu.subscribe(['change', 'resize'], function () { setTimeout(m, 0); }); this._updateWidth(); }; l.prototype._updateWidth = function () { 'use strict'; var m = this._menu.getRoot(), n = this._popoverMenu.getTriggerElem(), o = n.offsetWidth; i.set(m, 'min-width', o + 'px'); h.conditionClass(m, "_575s", o >= m.offsetWidth); }; Object.assign(l.prototype, { _setMenuSubscription: null, _showSubscription: null, _menuSubscription: null }); f.exports = l; }, null);
__d('PopoverMenuOverlappingBorder', ['CSS', 'DOM', 'Style', 'cx', 'shield'], function a(b, c, d, e, f, g, h, i, j, k, l) { if (c.__markCompiled) c.__markCompiled(); function m(n) { 'use strict'; this._popoverMenu = n; this._popover = n.getPopover(); this._triggerElem = n.getTriggerElem(); } m.prototype.enable = function () { 'use strict'; this._setMenuSubscription = this._popoverMenu.subscribe('setMenu', l(this._onSetMenu, this)); }; m.prototype.disable = function () { 'use strict'; this._popoverMenu.unsubscribe(this._setMenuSubscription); this._setMenuSubscription = null; this._removeBorderSubscriptions(); this._removeShortBorder(); }; m.prototype._onSetMenu = function () { 'use strict'; this._removeBorderSubscriptions(); this._menu = this._popoverMenu.getMenu(); this._renderShortBorder(this._menu.getRoot()); this._showSubscription = this._popover.subscribe('show', l(this._updateBorder, this)); var n = this._updateBorder.bind(this); this._menuSubscription = this._menu.subscribe(['change', 'resize'], function () { setTimeout(n, 0); }); this._updateBorder(); }; m.prototype._updateBorder = function () { 'use strict'; var n = this._menu.getRoot(), o = this._triggerElem.offsetWidth, p = Math.max(n.offsetWidth - o, 0); j.set(this._shortBorder, 'width', p + 'px'); }; m.prototype._renderShortBorder = function (n) { 'use strict'; this._shortBorder = i.create('div', { className: "_54hx" }); i.appendContent(n, this._shortBorder); h.addClass(n, "_54hy"); }; m.prototype._removeShortBorder = function () { 'use strict'; if (this._shortBorder) { i.remove(this._shortBorder); this._shortBorder = null; h.removeClass(this._popoverMenu.getMenu().getRoot(), "_54hy"); } }; m.prototype._removeBorderSubscriptions = function () { 'use strict'; if (this._showSubscription) { this._popover.unsubscribe(this._showSubscription); this._showSubscription = null; } if (this._menuSubscription) { this._menu.unsubscribe(this._menuSubscription); this._menuSubscription = null; } }; Object.assign(m.prototype, { _shortBorder: null, _setMenuSubscription: null, _showSubscription: null, _menuSubscription: null }); f.exports = m; }, null);
__d('ReactSelectorUtils', ['React'], function a(b, c, d, e, f, g, h) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var i = { processMenuItems: function (j, k) { var l, m = h.Children.map(j, function (n) { if (n) { var o = n.props.value === k; n = h.cloneElement(n, { selected: o }); if (o) l = n; return n; } }); return { items: m, selectedItem: l }; }, processMultiMenuItems: function (j, k) { var l = [], m = j; if (k) m = h.Children.map(j, function (n) { if (n) { var o = k.some(function (p) { return p === n.props.value; }); n = h.cloneElement(n, { selected: o }); if (o) l.push(n); return n; } }); return { items: m, selectedItems: l }; } }; f.exports = i; }, null);
__d('cloneWithProps', ['ReactElement', 'ReactPropTransferer', 'keyOf', 'warning'], function a(b, c, d, e, f, g, h, i, j, k) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var l = j({ children: null }), m = false; function n(o, p) { var q = i.mergeProps(p, o.props); if (!q.hasOwnProperty(l) && o.props.hasOwnProperty(l)) q.children = o.props.children; return h.createElement(o.type, q); } f.exports = n; }, null);
__d('AbstractSelector.react', ['InlineBlock.react', 'React', 'PopoverMenu.react', 'ReactSelectorUtils', 'ContextualLayerAutoFlip', 'PopoverMenuContextMinWidth', 'PopoverMenuOverlappingBorder', 'cloneWithProps', 'cx', 'invariant', 'joinClasses', 'intlList'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) { if (c.__markCompiled) c.__markCompiled(); var t = i.PropTypes; function u(w, x, y) { if (w[x] == null) return; var z = Array.isArray(w[x]); if (w.multiple) { if (!z) return new Error('You are trying to set a single value for `' + x + '` ' + 'but the menu has `multiple` set to true, so it should be an ' + 'array of values.'); } else if (z) return new Error('You are trying to set an array of values for `' + x + '` ' + 'but the menu has `multiple` set to false, so it should be a ' + 'single value.'); } var v = i.createClass({ displayName: 'AbstractSelector', propTypes: { config: t.object.isRequired, alignh: t.oneOf(['left', 'center', 'right']), name: t.string, overlappingborder: t.bool, onChange: t.func, disabled: t.bool, maxheight: t.number, multiple: t.bool, defaultLabel: t.string, defaultValue: u, value: u, initialValue: u }, getInitialState: function () { return { value: this.props.value != null ? this.props.value : this.props.defaultValue != null ? this.props.defaultValue : this.props.initialValue }; }, setMenuValue: function (w) { !(this.refs && this.refs.popover) ? q(0) : undefined; this._internalChange = true; this.refs.popover.getMenu().setValue(w); this._internalChange = false; }, onChange: function (w, x) { if (this._internalChange) return; if (this.props.value == null) { var y = null; if (this.props.multiple) { y = x.map(function (z) { return z.value; }); } else y = x.value; this.setState({ value: y }); } else this.setMenuValue(this.props.value); if (this.props.onChange) this.props.onChange(x); }, componentWillReceiveProps: function (w) { if (w.value != null) { this.setState({ value: w.value }); } else if (this.props.multiple !== w.multiple) this.setState({ value: w.multiple ? [this.state.value] : this.state.value[0] }); }, render: function () { var w = this.props.config, x = !this.props.multiple ? k.processMenuItems(this.props.children, this.state.value) : k.processMultiMenuItems(this.props.children, this.state.value), y = i.cloneElement(w.menu, { children: x.items, className: r("_575t", w.menu.props.className), maxheight: this.props.maxheight, onChange: this.onChange }), z = '', aa = null; if (!this.props.multiple) { var ba = x.selectedItem; z = ba.props.label || ba.props.children; if (ba.props.icon) aa = o(ba.props.icon, {}); } else { var ca = x.selectedItems; if (!ca.length) { z = this.props.defaultLabel; } else z = s(ca.map(function (ka) { return ka.props.children; }), s.CONJUNCTIONS.NONE); } var da = { label: z, disabled: this.props.disabled }; if (aa) da.image = aa; var ea = i.cloneElement(w.button, da), fa = [l]; if (w.layerBehaviors) fa = fa.concat(w.layerBehaviors); var ga = [m]; if (this.props.overlappingborder) ga.push(n); var ha = null; if (this.props.multiple) { var ia = this.props.name + '[]', ja; if (this.state.value) ja = this.state.value.map(function (ka) { return (i.createElement('input', { key: ka, type: 'hidden', name: ia, value: ka })); }); ha = i.createElement('div', null, ja); } else ha = i.createElement('input', { type: 'hidden', name: this.props.name, value: this.state.value }); return (i.createElement(h, babelHelpers._extends({}, this.props, { alignv: 'middle', name: null }), i.createElement(j, { ref: 'popover', menu: y, alignh: this.props.alignh, layerBehaviors: fa, behaviors: ga, disabled: this.props.disabled }, ea), ha)); }, showMenu: function () { !this.isMounted() ? q(0) : undefined; this.refs.popover.showPopover(); }, hideMenu: function () { !this.isMounted() ? q(0) : undefined; this.refs.popover.hidePopover(); } }); f.exports = v; }, null);
__d('AbstractCheckboxInput.react', ['React', 'cx', 'invariant', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = h.PropTypes, m = h.createClass({ displayName: 'AbstractCheckboxInput', propTypes: { tooltip: l.string }, render: function () { !(!this.props.children || this.props.children.length === 0) ? j(0) : undefined; var n = k(this.props.className, "_kv1"), o = h.createElement('input', babelHelpers._extends({}, this.props, { className: null, type: 'checkbox' }), undefined); return (h.createElement('label', { className: n }, o, h.createElement('span', { 'data-hover': this.props.tooltip ? 'tooltip' : null, 'aria-label': this.props.tooltip }))); } }); f.exports = m; }, null);
__d('XUICheckboxInput.react', ['AbstractCheckboxInput.react', 'React', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = i.createClass({ displayName: 'XUICheckboxInput', render: function () { return (i.createElement(h, babelHelpers._extends({}, this.props, { className: k(this.props.className, "_55sg") }), undefined)); } }); f.exports = l; }, null);
__d('XUINotice.react', ['React', 'Image.react', 'XUICloseButton.react', 'cx', 'fbt', 'ix', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var o = h.PropTypes, p = { notify: { altText: l._("Notice"), className: null, iconSrc: m('/images/deprecated/glyphs/flat/info-flat_m.png') }, success: { altText: l._("Success"), className: "_3qh4", iconSrc: m('/images/deprecated/glyphs/flat/checkmark_white_m.png') }, warn: { altText: l._("Warning"), className: "_585o", iconSrc: m('/images/deprecated/glyphs/flat/error-flat_m.png') } }, q = h.createClass({ displayName: 'XUINotice', propTypes: { onDismiss: o.func, use: o.oneOf(Object.keys(p)), size: o.oneOf(['medium', 'small']) }, getDefaultProps: function () { return { use: 'notify', size: 'medium' }; }, render: function () { var r = this.props, s = r.children, t = r.className, u = r.onDismiss, v = r.use, w = babelHelpers.objectWithoutProperties(r, ['children', 'className', 'onDismiss', 'use']), x = p[v]; t = n("_585n", x.className, t); var y = null; if (u) y = h.createElement(j, { className: "_585q", href: '#', onClick: u }); var z = "_585r" + (u ? ' ' + "_2i-a" : '') + (this.props.size === 'medium' ? ' ' + "_50f4" : '') + (this.props.size === 'small' ? ' ' + "_50f3" : ''); return (h.createElement('div', babelHelpers._extends({}, w, { className: t }), h.createElement(i, { alt: x.altText, className: "_585p", src: x.iconSrc }), y, h.createElement('div', { className: z }, s))); } }); f.exports = q; }, null);
__d('XUISelectorButton.react', ['React', 'XUIPopoverButton.react', 'invariant'], function a(b, c, d, e, f, g, h, i, j) { if (c.__markCompiled) c.__markCompiled(); var k = h.createClass({ displayName: 'XUISelectorButton', render: function () { !!this.props.theme ? j(0) : undefined; return (h.createElement(i, babelHelpers._extends({}, this.props, { theme: 'dark' }))); } }); f.exports = k; }, null);
__d('XUISelector.react', ['AbstractSelector.react', 'ContextualLayerPositionClassOnContext', 'React', 'ReactChildren', 'ReactXUIMenu', 'XUISelectorButton.react', 'invariant'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { if (c.__markCompiled) c.__markCompiled(); var o = l.SelectableMenu, p = l.SelectableItem, q = j.PropTypes, r = j.createClass({ displayName: 'ReactXUISelector', propTypes: { layerBehaviors: q.array, maxheight: q.number, multiple: q.bool, disabled: q.bool, haschevron: q.bool, maxwidth: q.number, size: q.oneOf(['small', 'medium', 'large', 'xlarge', 'xxlarge']), suppressed: q.bool, use: q.oneOf(['default', 'special', 'confirm']) }, statics: { getButtonSize: function (s) { return s.size || 'medium'; } }, getDefaultProps: function () { return { haschevron: true, layerBehaviors: [], multiple: false }; }, render: function () { var s, t = []; k.forEach(this.props.children, function (v) { if (v) t.push(v); }); if (t[0] && t[0].type === m) { s = t[0]; t = t.slice(1); } else s = j.createElement(m, { haschevron: this.props.haschevron, disabled: this.props.disabled, use: this.props.use, size: this.props.size, suppressed: this.props.suppressed, maxwidth: this.props.maxwidth }); var u = { button: s, menu: j.createElement(o, { maxheight: this.props.maxheight, multiple: this.props.multiple }), layerBehaviors: this.props.layerBehaviors.concat([i]) }; return (j.createElement(h, babelHelpers._extends({}, this.props, { ref: 'abstractSelector', config: u }), t)); }, showMenu: function () { !this.isMounted() ? n(0) : undefined; this.refs.abstractSelector.showMenu(); }, hideMenu: function () { !this.isMounted() ? n(0) : undefined; this.refs.abstractSelector.hideMenu(); } }); r.Option = p; f.exports = r; }, null);
__d('XUIRadioInput.react', ['React', 'cx', 'joinClasses', 'invariant'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = h.createClass({ displayName: 'XUIRadioInput', render: function () { !(!this.props.children || this.props.children.length === 0) ? k(0) : undefined; var m = j(this.props.className, "_55sh"), n = h.createElement('input', babelHelpers._extends({}, this.props, { className: null, type: 'radio' }), undefined); return (h.createElement('label', { className: m }, n, h.createElement('span', null))); } }); f.exports = l; }, null);
__d('Grid.react', ['React', 'ReactChildren', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = h.PropTypes, m = h.createClass({ displayName: 'Grid', propTypes: { cols: l.number.isRequired, fixed: l.bool, alignv: l.oneOf(['top', 'middle', 'bottom']), alignh: l.oneOf(['left', 'center', 'right']), spacing: l.string }, render: function () { var o = this.props, p = o.alignh, q = o.alignv, r = o.children, s = o.cols, t = o.fixed, u = o.spacing, v = i.count(r), w = [], x = [], y = 0; i.forEach(r, function (z, aa) { if (z === null || z === undefined) return; var ba = z.type === n; y += ba ? Math.max(z.props.colSpan || 0, 1) : 1; var ca = y === s ? "_51mw" : ''; if (!ba) { z = h.createElement(n, { alignh: p, alignv: q, className: k(u, ca), key: z.key || aa }, z); } else z = h.cloneElement(z, { key: z.key || aa, alignh: z.props.alignh || p, alignv: z.props.alignv || q, className: k(z.props.className, u, ca) }); x.push(z); if (y % s === 0 || aa + 1 === v) { if (t && y < s) { for (var da = y; da < s; da++)x.push(h.createElement(n, { key: aa + da })); y = s; } w.push(h.createElement('tr', { className: "_51mx", key: aa }, x)); x = []; y = 0; } }); return (h.createElement('table', babelHelpers._extends({}, this.props, { className: k(this.props.className, "uiGrid" + (' ' + "_51mz") + (t ? ' ' + "_5f0n" : '')), cellSpacing: '0', cellPadding: '0' }), h.createElement('tbody', null, w))); } }), n = h.createClass({ displayName: 'GridItem', propTypes: { alignv: l.oneOf(['top', 'middle', 'bottom']), alignh: l.oneOf(['left', 'center', 'right']) }, render: function () { var o = k(this.props.className, "_51m-" + (this.props.alignv === 'top' ? ' ' + "vTop" : '') + (this.props.alignv === 'middle' ? ' ' + "vMid" : '') + (this.props.alignv === 'bottom' ? ' ' + "vBot" : '') + (this.props.alignh === 'left' ? ' ' + "hLeft" : '') + (this.props.alignh === 'center' ? ' ' + "hCent" : '') + (this.props.alignh === 'right' ? ' ' + "hRght" : '')); return (h.createElement('td', babelHelpers._extends({}, this.props, { className: o }))); } }); m.GridItem = n; f.exports = m; }, null);