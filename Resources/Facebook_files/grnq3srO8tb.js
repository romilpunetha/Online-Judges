/*!CK:4197847442!*//*1444800984,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["CK36i"]); }

__d('ShareDialogTypeaheadViewItem.react', ['BackgroundImage.react', 'CurrentUser', 'ImageBlock.react', 'ImmutableObject', 'MercuryThreadImage.react', 'React', 'TypeaheadViewItem', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) { if (c.__markCompiled) c.__markCompiled(); var q = m.createClass({ displayName: 'ShareDialogTypeaheadViewItem', mixins: [n.Mixin], propTypes: n.propTypes, render: function () { var r = this.props.entry, s = this.props.splitSubtext ? r.getSubtitle().split(' \u00b7 ')[0] : r.getSubtitle(), t = s ? m.createElement('div', { className: "_599q" }, s) : null, u = r.getAuxiliaryData(); if (r.getPhoto()) { var v = m.createElement(h, { width: 32, height: 32, backgroundSize: 'cover', src: r.getPhoto() }); } else v = m.createElement(l, { size: 32, thread: new k(u.thread), viewer: i.getID() }); var w = "_599m" + (!t ? ' ' + "_5mne" : '') + (this.props.highlighted ? ' ' + "_599n" : ''); w = p(w, this.props.className); return (m.createElement('li', { 'aria-selected': this.props.highlighted, className: w, onMouseDown: this._onSelect, onMouseEnter: this._onHighlight, role: this.props.role }, m.createElement(j, { spacing: 'medium' }, v, m.createElement('div', null, m.createElement('div', { className: "_599p" + (!r.getPhoto() ? ' ' + "_3qmo" : '') }, r.getTitle()), t)))); } }); f.exports = q; }, null);